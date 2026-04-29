#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    int priority;
    string type;

public:
    Vehicle(string t, int p);
    int getPriority();
    string getType();
};

class Car : public Vehicle {
public:
    Car();
};

class Bike : public Vehicle {
public:
    Bike();
};

class Ambulance : public Vehicle {
public:
    Ambulance();
};

#endif