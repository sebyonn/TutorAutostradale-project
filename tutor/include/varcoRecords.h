//file scritto da Giacomo Dalla Riva

#ifndef varcoRecords_h
#define varcoRecords_h

#include <map>

//struttura per ogni varco
struct VarcoTutor
{
    int n_vehicles;
    int pos;
};

//classe per gestire i record dei varchi
class VarcoRecords
{
    public:
        //costruttore di default sempre chiamato a inizio timeline, crea una mappa vuota

        //member funcs
        void add_vehicle(int key);  //aggiunge 1 veicolo per varco
        void reset_varcorecords();

        //setter
        void insert_varco(int i, const VarcoTutor& a);

        //getter
        int get_nv(int key) const;
        int get_nkeys() const;
        VarcoTutor& at(int key);

    private:
        std::map<int, VarcoTutor> gates;
};

#endif