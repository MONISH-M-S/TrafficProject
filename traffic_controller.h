// ============================================================
// MODULE 5 — TRAFFIC CONTROLLER
// traffic_controller.h
// ============================================================
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include "road.h"
#include "traffic_signal.h"
#include "signal_transition.h"
#include "vehicle.h"

class TrafficController {
    Road r1, r2;
    TrafficSignal s1, s2;
    int roundNumber = 0;

    // ---- Print a separator line ----
    void line(char c = '-', int w = 44) const {
        std::cout << "  " << std::string(w, c) << "\n";
    }

    // ---- Set one road GREEN, the other RED, print reason ----
    void applyGreen(Road& /*green*/, Road& /*red*/,
                    TrafficSignal& sg, TrafficSignal& sr,
                    const std::string& reason) {
        sg.setState(SignalState::GREEN);
        sr.setState(SignalState::RED);
        std::cout << "  DECISION : " << reason << "\n";
    }

public:
    TrafficController() = default;

    // ---- Input: reset roads and fill with new vehicles ----
    void inputTraffic() {
        r1.clear();
        r2.clear();
        roundNumber++;

        int n = 0, amb = 0;

        line('=');
        std::cout << "  INPUT TRAFFIC -- Round " << roundNumber << "\n";
        line('=');

        std::cout << "  Normal vehicles on Road 1 : "; std::cin >> n;
        for (int i = 0; i < n; i++)
            r1.addVehicle(std::make_unique<Car>());

        std::cout << "  Ambulances    on Road 1   : "; std::cin >> amb;
        for (int i = 0; i < amb; i++)
            r1.addVehicle(std::make_unique<Ambulance>());

        std::cout << "  Normal vehicles on Road 2 : "; std::cin >> n;
        for (int i = 0; i < n; i++)
            r2.addVehicle(std::make_unique<Bike>());

        std::cout << "  Ambulances    on Road 2   : "; std::cin >> amb;
        for (int i = 0; i < amb; i++)
            r2.addVehicle(std::make_unique<Ambulance>());
    }

    // ---- Decision logic: Emergency > Volume ----
    void controlTraffic() {
        SignalTransition::showYellow();

        bool e1 = r1.hasEmergency();
        bool e2 = r2.hasEmergency();

        // ---- Priority 1: Emergency ----------------------------------------
        if (e1 && !e2) {
            applyGreen(r1, r2, s1, s2, "EMERGENCY on Road 1");

        } else if (!e1 && e2) {
            applyGreen(r2, r1, s2, s1, "EMERGENCY on Road 2");

        } else if (e1 && e2) {
            int a1 = r1.getAmbulanceCount();
            int a2 = r2.getAmbulanceCount();

            if (a1 > a2)
                applyGreen(r1, r2, s1, s2,
                    "BOTH EMERGENCY -- Road 1 has more ambulances ("
                    + std::to_string(a1) + " vs " + std::to_string(a2) + ")");
            else if (a2 > a1)
                applyGreen(r2, r1, s2, s1,
                    "BOTH EMERGENCY -- Road 2 has more ambulances ("
                    + std::to_string(a2) + " vs " + std::to_string(a1) + ")");
            else
                (r1.getVehicleCount() >= r2.getVehicleCount())
                    ? applyGreen(r1, r2, s1, s2,
                        "BOTH EMERGENCY, equal ambulances -- Road 1 higher volume")
                    : applyGreen(r2, r1, s2, s1,
                        "BOTH EMERGENCY, equal ambulances -- Road 2 higher volume");

        // ---- Priority 2: Normal traffic volume ----------------------------
        } else {
            if (r1.getVehicleCount() > r2.getVehicleCount())
                applyGreen(r1, r2, s1, s2,
                    "HIGH TRAFFIC -- Road 1 ("
                    + std::to_string(r1.getVehicleCount()) + " vs "
                    + std::to_string(r2.getVehicleCount()) + ")");
            else
                applyGreen(r2, r1, s2, s1,
                    "HIGH TRAFFIC -- Road 2 ("
                    + std::to_string(r2.getVehicleCount()) + " vs "
                    + std::to_string(r1.getVehicleCount()) + ")");
        }

        display();
    }

    // ---- Status display ----
    void display() const {
        std::cout << "\n";
        line('=');
        std::cout << "  TRAFFIC SYSTEM STATUS -- Round " << roundNumber << "\n";
        line('=');
        std::cout << "  Road 1  |  Signal: " << s1.getStateStr()
                  << "  |  Total: " << std::setw(2) << r1.getVehicleCount()
                  << "  (Amb: " << r1.getAmbulanceCount()
                  << "  Normal: "  << r1.getNormalCount() << ")\n";
        std::cout << "  Road 2  |  Signal: " << s2.getStateStr()
                  << "  |  Total: " << std::setw(2) << r2.getVehicleCount()
                  << "  (Amb: " << r2.getAmbulanceCount()
                  << "  Normal: "  << r2.getNormalCount() << ")\n";
        line('=');
    }
};
