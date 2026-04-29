#ifndef TRAFFICSIGNAL_H
#define TRAFFICSIGNAL_H

#include <string>
using namespace std;

class TrafficSignal {
    string state;
    int timer;

public:
    void setState(string s);
    void setTimer(int t);
    string getState();
    int getTimer();
};

#endif