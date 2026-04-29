// ============================================================
// MODULE 6 — MAIN
// main.cpp
// ============================================================
#include <iostream>
#include "traffic_controller.h"

int main() {
    TrafficController controller;
    int choice = 0;

    do {
        std::cout << "\n  ====== SMART TRAFFIC SYSTEM ======\n";
        std::cout << "  1. Run Simulation\n";
        std::cout << "  2. Exit\n";
        std::cout << "  Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            controller.inputTraffic();
            controller.controlTraffic();
        }

    } while (choice != 2);

    std::cout << "\n  Goodbye!\n";
    return 0;
}
