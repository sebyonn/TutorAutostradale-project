//file scritto da Sebastian Holospin

#ifndef userFuncs_h
#define userFuncs_h

#include "timeline.h"
#include "vehicleRecords.h"
#include "varcoRecords.h"

//FUNZIONI USER
void set_time(double& curr_time, Timeline& t, VarcoRecords& g, VehicleRecords& v);

//stampa le statistiche richieste
void stats(const double& curr_time, VarcoRecords& g, VehicleRecords& v);

//resetta tutti i record
void reset(Timeline& t, VarcoRecords& g, VehicleRecords& v);

//FUNCS D'APPOGGIO PER LE USER FUNCS
void latest_movement(const std::string& plate, VarcoRecords& g, VehicleRecords& v, const Event& e);

#endif