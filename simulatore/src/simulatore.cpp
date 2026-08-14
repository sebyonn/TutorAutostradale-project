//file scritto da Giacomo Dalla Riva

#include "../include/driveTracker.h"
#include "../include/traffic.h"
#include <iostream>
#include <fstream>

int main(void)
{
    try
    {
        Highway h = Highway("../Data/highway.txt");
        Traffic t = Traffic(h);

        std::ofstream r("../Data/Runs.txt");
        std::ofstream p("../Data/Passages.txt");

        for(int i = 0; i < t.get_size(); i++)
        {
            Vehicle& v = t.get_vehicle(i);
            new_car(v, h);
            logger(v, h, r, p);
        }

        r.close();
        p.close(); 
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}