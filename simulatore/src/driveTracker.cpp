//file creato da Sebastian Holospin

#include "../include/driveTracker.h"
#include "../include/randomFunc.h"
#include <fstream>
#include <iomanip>

const int v_min = 80;
const int v_max = 190;

const double t_min = 5*60;
const double t_max = 15*60; 

void new_car(Vehicle& a, const Highway& h)
{
    upd_speed_profile(a);
    a.curr_pos = h.s_pos(a.svincolo_in - 1);
    a.new_pos = a.curr_pos + a.speed_ms * a.duration_sec;
    a.next_varco = binsearch(h.get_varchi(), 0, h.get_varchi().size() - 2, a.curr_pos) + 1; 
}

bool has_exited(const Vehicle& a, const Highway& h)
{
    int out_pos = h.s_pos(a.svincolo_out - 1);
    bool exit = a.new_pos > out_pos;
    return exit;
}

double exit_time(const Vehicle& a, const Highway& h)
{
    int e_pos = h.s_pos(a.svincolo_out - 1);
    double e_time = ( (e_pos - a.curr_pos) / a.speed_ms ) + a.curr_time;
    return e_time;
}

bool has_passed(Vehicle& a, const Highway& h)
{
    int varco_pos = h.v_pos(a.next_varco - 1);
    bool passed = (a.new_pos >= varco_pos);
    return passed;
}

double passage_time(const Vehicle& a, const Varco& v)
{
    double p_time = ( (v.pos - a.curr_pos) / a.speed_ms ) + a.curr_time;
    return p_time;
}

void upd_speed_profile(Vehicle& a)
{
    int speed_kmh = random_int(v_min, v_max);
    a.speed_ms = (speed_kmh*1000)/3600;
    a.duration_sec = random_double(t_min, t_max);
}

void upd_pos(Vehicle& a, const Highway& h)
{
    a.curr_pos = a.new_pos;
    if(has_exited(a, h))
    {
        a.new_pos = h.s_pos(a.svincolo_out);
    } else
    {
        a.new_pos = a.curr_pos + a.speed_ms * a.duration_sec;
    }
}

void logger(Vehicle& a, const Highway h, std::ofstream& runs, std::ofstream& pass)
{
    runs << std::fixed << std::setprecision(2); //imposta 2 sole cifre post virgola nei double, per avere coerenza e ordine nei file
    pass << std::fixed << std::setprecision(2);
    
    runs << a.plate << " " << a.svincolo_in << " " << a.svincolo_out << " " << a.start_time << " ";

    double p_time = 0;
    int speed_kmh = 0;

    while(!(has_exited(a, h)))
    {

        while (a.next_varco > 0 && a.next_varco <= h.n_varchi() && has_passed(a, h)) //while e non if per controllare anche moltepliggi passaggi durante un solo intervallo
        {
            p_time = passage_time(a, h.varco_at(a.next_varco - 1));
            
            pass << a.next_varco << " " << a.plate << " " << p_time << "\n";
            a.next_varco++;
        }

        speed_kmh = (a.speed_ms * 3600) / 1000;
        runs << speed_kmh << " " << a.duration_sec << ", ";

        a.curr_time += a.duration_sec;

        upd_speed_profile(a);
        upd_pos(a, h);        
    }

    while (a.next_varco > 0 && a.next_varco <= h.n_varchi() && has_passed(a, h)) //while e non if per controllare anche moltepliggi passaggi durante un solo intervallo
    {
        p_time = passage_time(a, h.varco_at(a.next_varco - 1));
            
        pass << a.next_varco << " " << a.plate << " " << p_time << "\n";
        a.next_varco++;
    }

    double e_time = exit_time(a, h);
    double last_interval_time = e_time - a.curr_time;
    speed_kmh = (a.speed_ms * 3600) / 1000;
    
    runs << speed_kmh << " " << last_interval_time << "\n";
}

int binsearch(const std::vector<Varco>& vec, int pos_inizio, int pos_fine, int a)
{
    if (a < vec[0].pos)
    {
        return 0; //il varco in posizione 0, che è il primo varco dell'autostrada;
    }
    if (a > vec[pos_fine + 1].pos)
    {
        return -1; //errore, non ci sono più varchi post pos dell'auto, da gestire correttamente.
    }

    int mezzo = (pos_inizio+pos_fine)/2;
    
    if (vec[mezzo].pos <= a && a < vec[mezzo+1].pos)
    {
        return (mezzo + 1);  //indice 0-based del varco successivo in pozizione a vehicle
    }   
    if (a < vec[mezzo].pos)
    {
        return binsearch(vec, pos_inizio, mezzo, a);
    } else
    {
        return binsearch(vec, mezzo + 1, pos_fine, a);
    }
}