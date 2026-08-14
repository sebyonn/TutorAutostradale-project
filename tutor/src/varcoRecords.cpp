//file scritto da Giacomo Dalla Riva

#include "../include/varcoRecords.h"

//member funcs
void VarcoRecords::add_vehicle(int key)
{
    gates[key].n_vehicles++;
}

void VarcoRecords::reset_varcorecords()
{
    for(auto& pair : gates)
    {
        pair.second.n_vehicles = 0;
    }
}

//setter
void VarcoRecords::insert_varco(int i, const VarcoTutor& a)
{
    gates.insert(std::make_pair(i, a));
}

//getter
int VarcoRecords::get_nv(int key) const
{
    int nv = gates.at(key).n_vehicles;
    return nv;
}

int VarcoRecords::get_nkeys() const
{
    return gates.size();
}

VarcoTutor& VarcoRecords::at(int key)
{
    return gates.at(key);
}