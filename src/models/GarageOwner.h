#ifndef GARAGE_OWNER_H
#define GARAGE_OWNER_H

#include "Vehicle.h"
#include <string>

class GarageOwner {
private:
    string name;
    Vehicle** inventory;
    int vehicleCount;
    int capacity;

public:
    GarageOwner(string name);
    ~GarageOwner();

    string getName() const;
    void setName(const string& name);
    int getVehicleCount() const;

    bool addVehicle(Vehicle* vehicle);
    bool removeVehicle(int index);
    Vehicle* getVehicle(int index) const;
    void displayInventory() const;
    void sortByPrice();
    void sortByModel();
};

#endif // GARAGE_OWNER_H 