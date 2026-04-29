// ============================================================
// MODULE 2 — ROAD
// road.h
// ============================================================
#pragma once
#include <queue>
#include <memory>
#include "vehicle.h"

class Road {
    std::queue<std::unique_ptr<Vehicle>> vehicles;
    int ambulanceCount = 0;
    int normalCount    = 0;

public:
    Road() = default;
    Road(Road&&) = default;
    Road& operator=(Road&&) = default;

    void addVehicle(std::unique_ptr<Vehicle> v) {
        if (v->getPriority() == 1)
            ambulanceCount++;
        else
            normalCount++;
        vehicles.push(std::move(v));
    }

    int  getVehicleCount()   const { return static_cast<int>(vehicles.size()); }
    int  getAmbulanceCount() const { return ambulanceCount; }
    int  getNormalCount()    const { return normalCount; }
    bool hasEmergency()      const { return ambulanceCount > 0; }

    void processNext() {
        if (!vehicles.empty()) {
            if (vehicles.front()->getPriority() == 1)
                ambulanceCount--;
            else
                normalCount--;
            vehicles.pop();
        }
    }

    void clear() {
        while (!vehicles.empty()) vehicles.pop();
        ambulanceCount = 0;
        normalCount    = 0;
    }
};
