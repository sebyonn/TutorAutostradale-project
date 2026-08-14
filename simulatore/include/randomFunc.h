//file creato da Francesco Barban

/*
header d'appoggio per definire tutte le funzioni
volte a creare attributi randomici
da associare a determinati oggetti
*/

#ifndef randomFunc_h
#define randomFunc_h

#include <string>

//funzione per generare targhe randomiche 
//non richiede alcun parametro perché la dimensione della targa
//è fissata, del tipo "AA1111BB"
std::string random_plate_generator(); 

//funzioni per generare un numero randomico
//in un range che ha come estremi i parametri
//inseriti come argomento
int random_int(const int left, const int right);
double random_double(const double left, const double right);

#endif