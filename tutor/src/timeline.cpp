//file scritto da Francesco Barban

#include "../include/timeline.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iostream>

Timeline::Timeline(const std::string& file_name)
{
    std::fstream passages_file(file_name);
    if(!passages_file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + file_name);
    }

    //dati raccolti dal file
    int v_id;
    std::string pplate;
    double ttime;

    //variabile per rendere note eventuali righe d'errore
    int line_count = 0;

    std::string line;
    while(std::getline(passages_file, line))
    {
        line_count++;

        std::istringstream to_read(line);
        if(!(to_read >> v_id))
        {
            throw std::runtime_error("Invalid file: invalid varco_id at line " + std::to_string(line_count));
        }
        if(!(to_read >> pplate))
        {
            throw std::runtime_error("Invalid file: invalid plate at line " + std::to_string(line_count));
        }
        if(!(to_read >> ttime))
        {
            throw std::runtime_error("Invalid file: invalid time at line " + std::to_string(line_count));
        }

        schedule.push_back(Event{v_id, pplate, ttime});
    }

    std::sort(schedule.begin(), schedule.end());

    next_e = schedule.data();  //punta al primo elemento del vettore grazie a .data()
}

//member funcs
bool Timeline::in_time(double time) const
{
    if (end_of_timeline())
    {
        return false;
    }
    Event e = *next_e;
    return e.time <= time;
}

bool Timeline::end_of_timeline() const
{
    return next_e == schedule.data() + schedule.size(); //controlla se next_e punta fuori o dentro la timeline
}

void Timeline::reset_timeline()
{
    next_e = schedule.data();
}

//getter
Event Timeline::pop_front()
{
    Event e = *next_e;
    next_e++; //punta al prossimo elemento nel vettore
    return e;
}

bool operator<(const Event&a, const Event& b)
{
    return a.time < b.time;
}