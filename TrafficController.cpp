#include <iostream>
#include "TrafficController.h"
#include "FairnessManager.h"
#include "TimerManager.h"
#include "SignalTransition.h"

using namespace std;

void TrafficController::inputTraffic() {
    int n;

    cout << "Vehicles on Road 1: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        r1.addVehicle(new Car());

    cout << "Ambulance on Road 1? (1/0): ";
    cin >> n;
    if (n) r1.addVehicle(new Ambulance());

    cout << "Vehicles on Road 2: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        r2.addVehicle(new Bike());

    cout << "Ambulance on Road 2? (1/0): ";
    cin >> n;
    if (n) r2.addVehicle(new Ambulance());
}

void TrafficController::controlTraffic() {
    int t1 = TimerManager::calculateTime(r1.getVehicleCount());
    int t2 = TimerManager::calculateTime(r2.getVehicleCount());

    SignalTransition::showYellow();

    if (r1.hasEmergency()) {
        s1.setState("GREEN"); s2.setState("RED");
        cout << "Road 1 (Emergency)\n";
    }
    else if (r2.hasEmergency()) {
        s2.setState("GREEN"); s1.setState("RED");
        cout << "Road 2 (Emergency)\n";
    }
    else if (FairnessManager::checkFairness(r1)) {
        s1.setState("GREEN"); s2.setState("RED");
        cout << "Road 1 (Fairness)\n";
    }
    else if (FairnessManager::checkFairness(r2)) {
        s2.setState("GREEN"); s1.setState("RED");
        cout << "Road 2 (Fairness)\n";
    }
    else {
        if (r1.getVehicleCount() > r2.getVehicleCount()) {
            s1.setState("GREEN"); s2.setState("RED");
            cout << "Road 1 (High Traffic)\n";
        } else {
            s2.setState("GREEN"); s1.setState("RED");
            cout << "Road 2 (High Traffic)\n";
        }
    }

    display();
}

void TrafficController::display() {
    cout << "\nSignal 1: " << s1.getState() << endl;
    cout << "Signal 2: " << s2.getState() << endl;
}