//file scritto da Giacomo Dalla Riva

#ifndef vehicleRecords_h
#define vehicleRecords_h

#include <unordered_set>
#include <unordered_map>

#include <string>

//struttura per ogni veicolo
struct Vehicle
{
    double previous_passage;  //da settare appena inserito nella mappa
    double current_v_media;
    
    double total_time; //tempo trascorso da quando entra nel primo varco
    double total_v_media;
};

//classe per gestire i record dei veicoli
class VehicleRecords
{
    public:
        //costruttore di default già creato dal compilatore, non previsti altri costruttori

        //member func
        bool is_there(const std::string& plate);
        void reset_vehiclerecords();
        double global_v_media() const;

        //setter
        void insert_sanction(const std::string& plate);
        void insert_velocity(const std::string& plate, const Vehicle& a);

        //getter
        int get_sanctions() const;
        Vehicle& at(const std::string& key);

    private:
        std::unordered_set<std::string> sanctions;  //serve solo a sapere quante auto sono state sanzionando, garantendo l'unicità delle targhe al suo interno
        std::unordered_map<std::string, Vehicle> velocities;
};

#endif