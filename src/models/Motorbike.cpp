#include "Motorbike.h"

using namespace std;

Motorbike::Motorbike(string brand, double price, string model, string engineType, double maxSpeed)
    : Vehicle(brand, price, model), engineType(engineType), maxSpeed(maxSpeed) {
}

Motorbike::~Motorbike() {
}

string Motorbike::getEnType() const {
    return engineType;
}

double Motorbike::getSpeed() const {
    return maxSpeed;
}

void Motorbike::setEnType(const string& engineType) {
    this->engineType = engineType;
}

void Motorbike::setSpeed(double maxSpeed) {
    this->maxSpeed = maxSpeed;
}

void Motorbike::fuelConsumption() const {
    cout << "Motorbike fuel consumption depends on the engine type and size." << endl;
    cout << "This " << brand << " " << model << " with " << engineType << " engine has efficient fuel consumption." << endl;
}

void Motorbike::displayInf() const {
    cout << "==== Motorbike Information ====" << endl;
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Price: $" << price << endl;
    cout << "Engine Type: " << engineType << endl;
    cout << "Maximum Speed: " << maxSpeed << " km/h" << endl;
    cout << "===============================" << endl;
} 