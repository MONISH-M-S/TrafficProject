// ============================================================
// MODULE 4 — SIGNAL TRANSITION
// signal_transition.h
// ============================================================
#pragma once
#include <iostream>
#include <string>

namespace SignalTransition {

    inline void showYellow() {
        std::cout << "\n  [ YELLOW ] Evaluating traffic...\n";
    }

    inline void showChange(const std::string& from, const std::string& to) {
        std::cout << "  [Signal] " << from << " --> YELLOW --> " << to << "\n";
    }
}
