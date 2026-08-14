//file scritto da Francesco Barban

#include "../include/traffic.h"
#include "../include/randomFunc.h"
#include <unordered_set>

const int N_CARS = 10000;

Traffic::Traffic(const Highway& H)
{
	std::unordered_set<std::string> plates;

	size = 0;

	std::string plate;
	int svi_in;
	int svi_out;
	double start_time = 0;
	
	int i = 0;
	while (i < N_CARS) 
	{
		plate = random_plate_generator();

        if (plates.insert(plate).second)
        {
            svi_in = random_int(1, H.n_svincoli() - 1);
		    svi_out = random_int(svi_in + 1, H.n_svincoli());
		    start_time += random_double(0.5, 10);
            traffic.push_back(Vehicle(plate, svi_in, svi_out, start_time));
			size++;

            i++;
        }
	}

    plates.clear(); //non serve più il set, libera la memoria
}

Vehicle& Traffic::get_vehicle(int index)
{
	return traffic[index];
}

int Traffic::get_size() const
{
	return size;
}

