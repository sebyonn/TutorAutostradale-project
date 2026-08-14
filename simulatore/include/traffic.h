//file scritto da Francesco Barban

#ifndef traffic_h
#define traffic_h

#include "vehicle.h"
#include "highway.h"

class Traffic
{
	public:
		//Costruttore che genera le targhe, controllandone l'unicità e le inserisce nel vettore traffic
		Traffic(const Highway& H);

		//Restituisce il numero di veicoli nel traffico
		int get_size() const;

		//Restituisce il veicolo in posizione index nel vettore del traffico
		Vehicle& get_vehicle(int index);

	private:
		//Vettore di veicoli che compongono il traffico
    	std::vector<Vehicle> traffic;

		//Numero di veicoli nel traffico
		int size;
};

#endif // traffic