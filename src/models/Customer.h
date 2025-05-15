#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Vehicle.h"
#include <string>

class Customer {
private:
    string name;
    int contact;
    Vehicle** vehicles;
    int vehicleCount;
    int capacity;

public:
    Customer(string name, int contact);
    ~Customer();

    string getName() const;
    int getContact() const;
    void setName(const string& name);
    void setContact(int contact);

    bool purchaseVehicle(Vehicle* vehicle);
    void displayPurchasedVehicles() const;
    int getVehicleCount() const;
};

#endif // CUSTOMER_H 