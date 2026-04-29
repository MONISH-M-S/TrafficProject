// ============================================================
// MODULE 1 — VEHICLE
// vehicle.h
// ============================================================
#pragma once

class Vehicle {
protected:
    int priority;
public:
    explicit Vehicle(int p) : priority(p) {}
    virtual ~Vehicle() = default;

    virtual int getPriority() const { return priority; }
    virtual const char* getType() const = 0;
};

class Car : public Vehicle {
public:
    Car() : Vehicle(2) {}
    const char* getType() const override { return "Car"; }
};

class Bike : public Vehicle {
public:
    Bike() : Vehicle(2) {}
    const char* getType() const override { return "Bike"; }
};

class Ambulance : public Vehicle {
public:
    Ambulance() : Vehicle(1) {}
    const char* getType() const override { return "Ambulance"; }
};
