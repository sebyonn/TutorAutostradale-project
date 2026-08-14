//file scritto da Giacomo Della Riva
#include "../include/vehicle.h"
#include <iostream>

Vehicle::Vehicle()
{
    plate = "";
    svincolo_in = 0;
    svincolo_out = 0;
    start_time = 0;
    speed_ms = 0;
    duration_sec = 0;
    curr_pos = 0;
    new_pos = 0;
    next_varco = 0;
    curr_time = 0;
}

Vehicle::Vehicle(const std::string& pplate, int ssvincolo_in, int ssvincolo_out, double sstart_time)
{
    //variabili che identificano lo stato iniziale di auto
    plate = pplate;
    svincolo_in = ssvincolo_in;
    svincolo_out = ssvincolo_out;
    start_time = sstart_time;
    curr_time = sstart_time;
    
    //variabili che verranno modificate post-creazione di auto
    speed_ms = 0;
    duration_sec = 0;
    curr_pos = 0;
    new_pos = 0;
    next_varco = 0;
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    plate = other.plate;
    svincolo_in = other.svincolo_in;
    svincolo_out = other.svincolo_out;
    start_time = other.start_time;
    curr_time = other.curr_time;
    speed_ms = other.speed_ms;
    duration_sec = other.duration_sec;
    curr_pos = other.curr_pos;
    new_pos = other.new_pos;
    next_varco = other.next_varco;

    return *this;
}
