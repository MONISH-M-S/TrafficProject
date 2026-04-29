#ifndef ROAD_H
#define ROAD_H

#include <queue>
#include "Vehicle.h"

class Road {
    std::queue<Vehicle*> vehicles;
    int waitTime;

public:
    Road();

    void addVehicle(Vehicle* v);
    int getVehicleCount();
    bool hasEmergency();

    void incrementWait();
    void resetWait();
    int getWaitTime();
};

#endif