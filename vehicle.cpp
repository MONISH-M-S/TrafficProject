#include "Vehicle.h"

Vehicle::Vehicle(string t, int p) {
    type = t;
    priority = p;
}

int Vehicle::getPriority() {
    return priority;
}

string Vehicle::getType() {
    return type;
}

Car::Car() : Vehicle("Car", 2) {}
Bike::Bike() : Vehicle("Bike", 2) {}
Ambulance::Ambulance() : Vehicle("Ambulance", 1) {}