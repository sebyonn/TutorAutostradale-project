//file scritto da Giacomo Dalla Riva

#include "../include/vehicleRecords.h"

//MEMBER FUNCS

bool VehicleRecords::is_there(const std::string& plate)
{
    return velocities.find(plate) != velocities.end();
}

void VehicleRecords::reset_vehiclerecords()
{
    sanctions.clear();
    velocities.clear();
}

double VehicleRecords::global_v_media() const
{
    double v_sum = 0;
    int total_v = velocities.size();
    double global_v = 0;
	int undetected = 0;

    if (total_v == 0)
    {
        return global_v;
    }

    for (const auto& pair : velocities)
    {
        v_sum += pair.second.total_v_media;
		if (pair.second.total_v_media == 0)
		{
			undetected++;
		}
    }
    if (total_v > undetected) //se == divione per 0, non mi aspetto valori <
	{
		global_v = v_sum / (total_v - undetected);
	}
	//global_v =0; // è gia =0
    return global_v;
}

//SETTER FUNCS
void VehicleRecords::insert_sanction(const std::string& plate)
{
    sanctions.insert(plate);
}

void VehicleRecords::insert_velocity(const std::string& plate, const Vehicle& a)
{
    velocities.insert(std::make_pair(plate, a));
}

//GETTER FUNCS
int VehicleRecords::get_sanctions() const
{
    return sanctions.size();
}

Vehicle& VehicleRecords::at(const std::string& key)
{
    return velocities.at(key);
}