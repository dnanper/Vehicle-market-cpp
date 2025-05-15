#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <limits>
#include <climits>
#include "../models/GarageOwner.h"
#include "../models/Customer.h"

using namespace std;

namespace Utils {
    int getIntInput(const string& prompt, int min = INT_MIN, int max = INT_MAX);
    double getDoubleInput(const string& prompt, double min = -1000000.0, double max = 1000000.0);
    string getStringInput(const string& prompt);
    
    void displayMainMenu();
    void displayGarageOwnerMenu();
    void displayCustomerMenu();
    
    void addCarToGarage(GarageOwner& owner);
    void addMotorbikeToGarage(GarageOwner& owner);
    
    bool purchaseVehicleFromGarage(GarageOwner& owner, Customer& customer);
}

#endif // UTILS_H 