//file scritto da Sebastian Holospin

#include "../include/userFuncs.h"
#include <iostream>

const int MAX_VELOCITY = 130;

void set_time(double& curr_time, Timeline& t, VarcoRecords& g, VehicleRecords& v)
{
    if (curr_time < 0)
    {
        throw std::invalid_argument("Error: l'argomento temporale passato è negativo");
    }
    while (t.in_time(curr_time) && !(t.end_of_timeline()))
    {
        Event e = t.pop_front();
        
        g.add_vehicle(e.varco_id);
        if(v.is_there(e.plate))
        {
            latest_movement(e.plate, g, v, e);
        } else
        {
            Vehicle a{e.time, 0, 0, 0};
            v.insert_velocity(e.plate, a);
        }
    }

    if (t.end_of_timeline())
    {
        std::cout << "Warning: non ci sono più auto in circolazione\n";
    }
}

void stats(const double& curr_time, VarcoRecords& g, VehicleRecords& v)
{
    double mins = curr_time / 60; //curr_time è in secondi.

    std::cout << "VEICOLI PER VARCO (TOTALI : AL MINUTO)\n";
    int n;
    double n_media;
    for (int i = 1; i <= g.get_nkeys(); i++)
    {
        n = g.get_nv(i);
        n_media = n / mins;

        std::cout << "Varco " << i << " " << n << " : " << n_media << "\n";
    }

    std::cout << "MEDIA GLOBALE VELOCITA' DEI VEICOLI\n";
    double global_v = v.global_v_media();
    std::cout << "velocità media: " << global_v << "\n";

    std::cout << "SANZIONI\n";
    int sanz = v.get_sanctions();
    std::cout << "veicoli sanzionati: " << sanz << "\n";
}

void reset(Timeline& t, VarcoRecords& g, VehicleRecords& v)
{
    t.reset_timeline();
    g.reset_varcorecords();
    v.reset_vehiclerecords();
}

//FUNCS D'APPOGGIO
void latest_movement(const std::string& plate, VarcoRecords& g, VehicleRecords& v, const Event& e)
{
    Vehicle& a = v.at(plate);
    
    int dist = g.at(e.varco_id).pos - g.at(e.varco_id - 1).pos;
    double delta_time = e.time - a.previous_passage;
    
    int v_media_ms = dist / delta_time;
    a.current_v_media = v_media_ms*3.6; //conversione da ms a kmh

    a.total_v_media = (a.total_v_media*a.total_time + delta_time*a.current_v_media) / (a.total_time + delta_time);
    a.total_time += delta_time;

    if(a.current_v_media > MAX_VELOCITY)
    {
        v.insert_sanction(plate);

        std::cout << "Veicolo " << plate << " sanzionato nella tratta tra il varco " << e.varco_id - 1 << " e il varco " << e.varco_id << ":\n";
        std::cout << "   - istante d'entrata: " << a.previous_passage << "\n";
        std::cout << "   - istante d'uscita: " << e.time << "\n";
        std::cout << "   - velocità media: " << a.current_v_media << "\n";
    }

    a.previous_passage = e.time;
}

