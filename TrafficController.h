#ifndef TRAFFICCONTROLLER_H
#define TRAFFICCONTROLLER_H

#include "Road.h"
#include "TrafficSignal.h"

class TrafficController {
    Road r1, r2;
    TrafficSignal s1, s2;

public:
    void inputTraffic();
    void controlTraffic();
    void display();
};

#endif