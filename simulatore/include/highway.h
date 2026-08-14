//file creato da Sebastian Holospin

#ifndef highway_h
#define highway_h

#include <vector>
#include <string>

//Oggetto che rappresenta un varco sull'autostrada
struct Varco
{
    int pos;  //posizione in metri del varco sull'autostrada
    int vehicles; //numero di macchine passate sotto il varco
};

//Operatore per poter usare l'algoritmo std::sort sui varchi
bool operator<(const Varco& a, const Varco& b);

//Oggetto che rappresenta uno svincolo sull'autostrada
struct Svincolo
{
    int pos;  //posizione in metri dello svincolo sull'autostrada
};

//Operatore per poter usare l'algoritmo std::sort sugli svincoli
bool operator<(const Svincolo& a, const Svincolo& b);

//Classe che serve a creare l'oggetto autostrada, su cui poi lavorerà il simulatore. Gestisce il file di input, affinché vengano rispettate le condizioni di autostrada valida. Non è previsto un costruttore di default, poiché tutte le autostrade possibili vengono passate tramite file di testo.
class Highway
{
    public:
        //unico costruttore previsto: passaggio per file
        Highway(const std::string& file_name); 

        //Restituisce il numero di svincoli nell'autostrada
        int n_svincoli() const;

        //Restituisce il numero di varchi nell'autostrada
        int n_varchi() const;
        
        //Restituisce la posizione dello svincolo in indice index
        int s_pos(int index) const;
        
        //Restituisce la posizione del varco in indice index
        int v_pos(int index) const;
        
        //Restituisce il varco in indice index
        Varco varco_at(int index) const;
        
        //Restituisce il vettore dei varchi
        const std::vector<Varco>& get_varchi() const;

    private:
        //Vector di varchi e svincoli che caratterizzano l'autostrada
        std::vector<Varco> varchi;
        std::vector<Svincolo> svincoli;
};

#endif