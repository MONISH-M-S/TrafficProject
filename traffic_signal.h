// ============================================================
// MODULE 3 — TRAFFIC SIGNAL
// traffic_signal.h
// ============================================================
#pragma once
#include <string>

enum class SignalState { RED, YELLOW, GREEN };

class TrafficSignal {
    SignalState state = SignalState::RED;

public:
    void setState(SignalState s) { state = s; }
    SignalState getState() const { return state; }

    std::string getStateStr() const {
        switch (state) {
            case SignalState::RED:    return "RED   ";
            case SignalState::YELLOW: return "YELLOW";
            case SignalState::GREEN:  return "GREEN ";
        }
        return "UNKNOWN";
    }

    bool isGreen() const { return state == SignalState::GREEN; }
    bool isRed()   const { return state == SignalState::RED;   }
};
