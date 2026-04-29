#include "TrafficSignal.h"

void TrafficSignal::setState(string s) {
    state = s;
}

void TrafficSignal::setTimer(int t) {
    timer = t;
}

string TrafficSignal::getState() {
    return state;
}

int TrafficSignal::getTimer() {
    return timer;
}