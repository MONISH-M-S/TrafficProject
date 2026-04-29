#include "Road.h"

Road::Road() {
    waitTime = 0;
}

void Road::addVehicle(Vehicle* v) {
    vehicles.push(v);
}

int Road::getVehicleCount() {
    return vehicles.size();
}

bool Road::hasEmergency() {
    std::queue<Vehicle*> temp = vehicles;

    while (!temp.empty()) {
        if (temp.front()->getPriority() == 1)
            return true;
        temp.pop();
    }
    return false;
}

void Road::incrementWait() {
    waitTime++;
}

void Road::resetWait() {
    waitTime = 0;
}

int Road::getWaitTime() {
    return waitTime;
}