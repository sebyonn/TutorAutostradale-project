//file scritto da Francesco Barban

#ifndef timeline_h
#define timeline_h

#include <string>
#include <vector>

//definizione di un evento
struct Event
{
    int varco_id;
    std::string plate;
    double time;
};

//overload dell'operatore < per ordinare gli eventi in base al tempo
bool operator<(const Event& a, const Event& b);

class Timeline
{
    public:
        Timeline(const std::string& file_name);  //unico costruttore previsto

        //member funcs
        bool in_time(double time) const;
        bool end_of_timeline() const;
        void reset_timeline();

        //ritorna e rimuove il primo elemento della lista
        Event pop_front();

    private:
        std::vector<Event> schedule;
        Event* next_e;
};

#endif