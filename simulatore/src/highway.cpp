//file scritto da Sebastian Holospin

#include "../include/highway.h"
#include <fstream> //libreria per leggere e scrivere file
#include <sstream>  //libreria per trasformare stringhe in flussi leggibili come fossero file
#include <iostream>
#include <stdexcept>
#include <algorithm>

Highway::Highway(const std::string& file_name)
{
    std::fstream highway_file(file_name);
    if (!highway_file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + file_name);
    }

    //conteggio di varchi e svincoli, da assegnare al loro id
    int svincoli_count = 0;
    int varchi_count = 0;

    //eventuali flags o conteggi per lanciare eccezioni
    int line_count = 0;

    //dati raccolti dal file
    int dist;
    std::string obj; //per obj si intende V o S

    //lettura effettiva del file per righe e raccoglimento dei dati
    std::string line;
    while (std::getline(highway_file, line))  //restituisce false quando non riesce a trovare una nuova riga (EOF)
    {
        line_count++;

        std::istringstream to_read(line); //rende line leggibile come fosse un file
        if (!(to_read >> dist))
        {
            throw std::runtime_error("Invalid file: invalid distance at line " + std::to_string(line_count));
        }
        if (!(to_read >> obj)) //obj è stringa, l'unico caso in cui to_read non può inserire nulla in obj è se la riga si è conclusa
        {
            throw std::runtime_error("Invalid file: missing varco or svincolo at line " + std::to_string(line_count));
        }

        //obj e dist sono già stati modificati nel check degli if, non serve ritoccarli
        if (obj == "V")
        {
            varchi.push_back(Varco{dist*1000, 0}); //trasforma i km in m
            varchi_count++;
        } else if (obj == "S")
        {
            svincoli.push_back(Svincolo{dist*1000});
            svincoli_count++;
        } else
        {
            throw std::runtime_error("Invalid file: invalid gate type at line " + std::to_string(line_count));
        }
    }

    //controllo della presenza di almeno due varchi
    if (varchi_count < 2)
    {
        throw std::runtime_error("Invalid file: there MUST be at least 2 varchi");
    }

    //ordinamento dei svincoli e dei varchi nel vettore.
    std::sort(varchi.begin(), varchi.end());
    std::sort(svincoli.begin(), svincoli.end());

    //controllo che il primo gate sia uno svincolo
    if (svincoli[0].pos > varchi[0].pos)
    {
        throw std::runtime_error("Invalid file: first gate type MUST be \"svincolo\"");
    }

    //controllo che l'ultimo gate sia uno svincolo
    if (svincoli[svincoli_count-1].pos < varchi[varchi_count-1].pos)
    {
        throw std::runtime_error("Invalid file: last gate type MUST be \"svincolo\"");
    }

    //controllo che ci sia una distanza minima di 1km tra ogni vincolo e svarco
    /*
    il ciclo che segue non resetta mai j, evitando così che ogni volta vengano controllati tutti gli
    svincoli per ogni varco.
    funziona solo nell'ipotesi che svincoli e varchi siano ordinati.
    */
    auto j = 0u;
    for (auto i = 0u; i < varchi.size(); i++) //auto e non int perché varchi.size() rilascia un unsigned long
    {
        while (varchi[i].pos > svincoli[j].pos && j < svincoli.size())
        {
            if ((varchi[i].pos - svincoli[j].pos) < 1000)
            {
                throw std::runtime_error("Invalid file: minimum distance between varchi and svincoli must be 1 km");
            }
            j++;
        }
        
        /*
        nell'if che segue vengono omessi i bound check su j perché il primo svincolo ha pos < primo varco,
        per cui j != 0 in ogni caso a questo punto del codice.
        parimenti, l'ultimo svincolo ha pos > ultimo varco, per cui è certo che, per come funziona il ciclo while, si raggiungerà
        j = svincoli.size() - 1 solo quando si sarà raggiunto anche i = varchi.size() - 1, uscendo dunque dal ciclo for
        prima di sforare con j.
        */

        //check anche del solo vincolo immediatamente successivo al varco considerato.

        if ((svincoli[j].pos - varchi[i].pos ) < 1000) //fa il controllo anche con lo svincolo successivo di posizione
        {
            throw std::runtime_error("Invalid file: minimum distance between varchi and svincoli must be 1 km");
        }
    }

}

int Highway::n_svincoli() const
{
    return svincoli.size();
}

int Highway::n_varchi() const
{
    return varchi.size();
}

int Highway::s_pos(int index) const
{
    return svincoli[index].pos;
}

int Highway::v_pos(int index) const
{
    return varchi[index].pos;
}

Varco Highway::varco_at(int index) const
{
    return varchi[index];
}

const std::vector<Varco>& Highway::get_varchi() const
{
    return varchi;
}

bool operator<(const Varco& a, const Varco& b)
{
    return a.pos < b.pos;
}

bool operator<(const Svincolo& a, const Svincolo& b)
{
    return a.pos < b.pos;
}