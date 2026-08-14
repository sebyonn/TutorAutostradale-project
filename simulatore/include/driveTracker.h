//File creato da Sebastian Holospin

#ifndef driveTracker_h
#define driveTracker_h

#include "vehicle.h"
#include "highway.h"
#include <string>

//Inizializza le variabili di Vehicle che non sono state settate dal costruttore.
void new_car(Vehicle& a, const Highway& h);

//Controlla se Vehicle è uscito dall'autostrada con il suo attuale profilo di velocità.
bool has_exited(const Vehicle& a, const Highway& h);

//Calcola il tempo di uscita dall'autostrada di Vehicle.
double exit_time(const Vehicle& a, const Highway& h);

//Controlla se Vehicle è passato con il suo attuale profilo di velocità oltre il varco successivo nel suo cammino. Aggiorna la variabile next_varco di Vehicle se ritorna true.
bool has_passed(Vehicle& a, const Highway& h);

//Calcola il tempo di passaggio di Vehicle oltre il varco v.
double passage_time(const Vehicle& a, const Varco& v);

//Aggiorna il profilo di velocità di Vehicle in maniera casuale.
void upd_speed_profile(Vehicle& a);

//Aggiorna la posizione di Vehicle dopo il suo attuale profilo di velocità. Prima di fare ciò, verifica che Vehicle non sia uscito dall'autostrada.
void upd_pos(Vehicle& a);

//Funzione che fa eseguire tutti i movimenti necessari alla macchina fino a farla uscire dall'autostrada. Ritorna una stringa con le sue informazioni rilevanti.
void logger(Vehicle& a, const Highway h, std::ofstream& runs, std::ofstream& pass);

//Rivisitazione del metodo binary search per confrontare la posizione iniziale del veicolo con quelle dei varchi, così da poter determinare il primo varco che il veicolo incontrerà.
int binsearch(const std::vector<Varco>& vec, int pos_inizio, int pos_fine, int a);

#endif