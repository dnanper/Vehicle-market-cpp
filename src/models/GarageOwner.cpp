#include "GarageOwner.h"
#include "Car.h"
#include "Motorbike.h"
#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

GarageOwner::GarageOwner(string name)
    : name(name), vehicleCount(0), capacity(1000) {
    inventory = new Vehicle*[capacity];
    for (int i = 0; i < capacity; i++) {
        inventory[i] = nullptr;
    }
}

GarageOwner::~GarageOwner() {
    for (int i = 0; i < vehicleCount; i++) {
        delete inventory[i];
    }
    delete[] inventory;
}

string GarageOwner::getName() const {
    return name;
}

void GarageOwner::setName(const string& name) {
    this->name = name;
}

int GarageOwner::getVehicleCount() const {
    return vehicleCount;
}

bool GarageOwner::addVehicle(Vehicle* vehicle) {
    inventory[vehicleCount] = vehicle;
    vehicleCount++;
    cout << "Vehicle added to inventory successfully!" << endl;
    return true;
}

bool GarageOwner::removeVehicle(int index) {
    if (index < 0 || index >= vehicleCount) {
        cout << "Invalid vehicle index!" << endl;
        return false;
    }
    
    for (int i = index; i < vehicleCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    inventory[vehicleCount - 1] = nullptr;
    vehicleCount--;
    cout << "Vehicle removed from inventory." << endl;
    return true;
}

Vehicle* GarageOwner::getVehicle(int index) const {
    if (index < 0 || index >= vehicleCount) {
        return nullptr;
    }
    return inventory[index];
}

void GarageOwner::displayInventory() const {
    if (vehicleCount == 0) {
        cout << name << "'s garage has no vehicles in inventory." << endl;
        return;
    }
    
    cout << "===== " << name << "'s Garage Inventory =====" << endl;
    
    cout << "\n----- Cars -----" << endl;
    int carCount = 0;
    for (int i = 0; i < vehicleCount; i++) {
        Car* car = dynamic_cast<Car*>(inventory[i]);
        if (car) {
            cout << "\nVehicle " << (i + 1) << ":" << endl;
            car->displayInf();
            carCount++;
        }
    }
    
    if (carCount == 0) {
        cout << "No cars in inventory." << endl;
    }
    
    cout << "\n----- Motorbikes -----" << endl;
    int motorbikeCount = 0;
    for (int i = 0; i < vehicleCount; i++) {
        Motorbike* motorbike = dynamic_cast<Motorbike*>(inventory[i]);
        if (motorbike) {
            cout << "\nVehicle " << (i + 1) << ":" << endl;
            motorbike->displayInf();
            motorbikeCount++;
        }
    }
    
    if (motorbikeCount == 0) {
        cout << "No motorbikes in inventory." << endl;
    }
    
    cout << "=====================================" << endl;
}

void GarageOwner::sortByPrice() {
    if (vehicleCount <= 1) {
        return;
    }
    
    for (int i = 0; i < vehicleCount - 1; i++) {
        for (int j = 0; j < vehicleCount - i - 1; j++) {
            if (inventory[j]->getPrice() > inventory[j + 1]->getPrice()) {
                Vehicle* temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
    
    cout << "Inventory sorted by price (ascending)." << endl;
}

void GarageOwner::sortByModel() {
    if (vehicleCount <= 1) {
        return;
    }
    
    for (int i = 0; i < vehicleCount - 1; i++) {
        for (int j = 0; j < vehicleCount - i - 1; j++) {
            if (inventory[j]->getModel() > inventory[j + 1]->getModel()) {
                Vehicle* temp = inventory[j];
                inventory[j] = inventory[j + 1];
                inventory[j + 1] = temp;
            }
        }
    }
    
    cout << "Inventory sorted by model (alphabetically)." << endl;
} 