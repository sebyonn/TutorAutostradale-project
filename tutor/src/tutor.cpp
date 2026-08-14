//file scritto da Sebastian Holospin

#include "../../simulatore/include/highway.h"
#include "../include/timeline.h"
#include "../include/userFuncs.h"

#include <iostream>
#include <sstream>

int main(void)
{
    double time = 0;
    int add_time;

    std::string input;
    std::string command;
    std::string s_time;

    std::string extra; //controlla che per comandi oltre a set_time non vi sia scritto nient'altro oltre al comando stesso
    
    bool done = false;
    
    try {
        //inizializzazioni varie
        Highway h = Highway("../Data/highway.txt");
        VarcoRecords gates;
        std::vector<Varco> varchi = h.get_varchi();
        for (auto i = 1u; i <= varchi.size(); i++)
        {
            gates.insert_varco(i, VarcoTutor{0, varchi[i-1].pos});
        }
        VehicleRecords vr;
        Timeline t = Timeline("../Data/Passages.txt");

        while (!done)
        {
            //RICHIESTA COMANDI SU TERMINALE
            std::cout << "\nINSERIRE UNO DEI SEGUENTI COMANDI:\n";
            std::cout << "   - set_time <secondi o minuti>\n";
            std::cout << "   - stats\n";
            std::cout << "   - reset\n";
            std::cout << "   - stop\n\n";

            std::cout << "> ";

            std::getline(std::cin, input);
            std::stringstream ss(input);
            ss >> command;

            if(command == "set_time")
            {
                if (!(ss >> s_time))
                {
                    std::cout << "\nerror: missing time";
                } else
                {
                    char unit = '\0'; //nessun valore effettivo
                    if (std::isalpha(s_time.back()))
                    {
                        unit = s_time.back();
                        s_time.pop_back();
                    }
                    std::stringstream st(s_time);
                    if(st >> add_time) 
                    {
                        if (unit == 'm')
                        {
                            add_time *= 60;  //conversione da minuti a secondi;
                            time += add_time;
                            set_time(time, t, gates, vr);
                        } else if (unit == '\0')
                        {
                            time += add_time;
                            set_time(time, t, gates, vr);
                        } else
                        {
                            std::cout << "\nInvalid command: retry\n";
                        }
                    } else  
                    {
                        std::cout << "\nInvalid command: retry\n";
                    }
                }
            } 
            else if (command == "stats" && !(ss >> extra))
            {
                stats(time, gates, vr);
            }
            else if(command == "reset" && !(ss >> extra))
            {
                reset(t, gates, vr);
                time = 0;
            }
            else if(command == "stop" && !(ss >> extra))
            {
                done = true;
            }
            else
            {
                std::cout << "\nInvalid command, retry\n";
            }
        }

    } catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}