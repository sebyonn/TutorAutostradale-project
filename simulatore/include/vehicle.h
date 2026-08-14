//File scritto da Giacomo Dalla Riva

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

struct Vehicle
{
    Vehicle();
    Vehicle(const Vehicle&) = default;
    Vehicle(const std::string& pplate, int ssvincolo_in, int ssincolo_out, double sstart_time);

    Vehicle& operator=(const Vehicle& other);
    
    //VARIABILI CHE DEFINISCONO OGNI MACCHINA

    std::string plate;  //identificativo UNICO dell'auto, verrà usato come chiave per l'hash map
    
    int svincolo_in;    //svincolo d'entrata dell'auto
    int svincolo_out;   //svincolo d'uscita dell'auto
    double start_time;  //tempo t a cui l'auto entra in autostrada
    double curr_time;   //tempo t corrispondente alla posizione iniziale dell'auto nell'attuale profilo di velocità

    //informazioni per passaggi tra i varchi
    int next_varco;

    //profilo di velocità
    double speed_ms;        //velocità dell'auto in metri al secondo
    double duration_sec;    //tempo in cui l'auto mantiene la sua velocità attuale

    //posizioni rilevanti per sapere se la macchina passerà sotto un varco o meno
    int curr_pos;   //posizione corrente prima di un nuovo profilo di velocità
    int new_pos;     //nuova posizione post-profilo di velocità
   
};

#endif