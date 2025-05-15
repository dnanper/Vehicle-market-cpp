#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    string color;
    int numSeat;

public:
    Car(string brand, double price, string model, string color, int numSeat);
    ~Car() override;

    string getColor() const;
    int getNumSeat() const;
    void setColor(const string& color);
    void setNumSeat(int numSeat);

    void fuelConsumption() const override;
    void displayInf() const override;
};

#endif // CAR_H 