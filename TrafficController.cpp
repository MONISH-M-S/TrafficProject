#include <iostream>
#include "TrafficController.h"
#include "FairnessManager.h"
#include "TimerManager.h"
#include "SignalTransition.h"

using namespace std;

void TrafficController::inputTraffic() {
    int n, amb;

    cout << "\n=========== INPUT TRAFFIC DATA ===========\n";

    cout << "Vehicles on Road 1 (excluding ambulance): ";
    cin >> n;
    for (int i = 0; i < n; i++)
        r1.addVehicle(new Car());

    cout << "Ambulance count on Road 1: ";
    cin >> amb;
    for (int i = 0; i < amb; i++)
        r1.addVehicle(new Ambulance());

    cout << "Vehicles on Road 2 (excluding ambulance): ";
    cin >> n;
    for (int i = 0; i < n; i++)
        r2.addVehicle(new Bike());

    cout << "Ambulance count on Road 2: ";
    cin >> amb;
    for (int i = 0; i < amb; i++)
        r2.addVehicle(new Ambulance());
}

void TrafficController::controlTraffic() {

    SignalTransition::showYellow();

    if (r1.hasEmergency()) {
        s1.setState("GREEN"); s2.setState("RED");

        cout << "\n>>> PRIORITY: EMERGENCY DETECTED <<<\n";
        cout << ">>> GREEN SIGNAL GIVEN TO ROAD 1 <<<\n";

        r1.resetWait(); r2.incrementWait();
    }
    else if (r2.hasEmergency()) {
        s2.setState("GREEN"); s1.setState("RED");

        cout << "\n>>> PRIORITY: EMERGENCY DETECTED <<<\n";
        cout << ">>> GREEN SIGNAL GIVEN TO ROAD 2 <<<\n";

        r2.resetWait(); r1.incrementWait();
    }
    else if (FairnessManager::checkFairness(r1)) {
        s1.setState("GREEN"); s2.setState("RED");

        cout << "\n>>> FAIRNESS RULE ACTIVATED <<<\n";
        cout << ">>> GREEN SIGNAL GIVEN TO ROAD 1 <<<\n";

        r1.resetWait(); r2.incrementWait();
    }
    else if (FairnessManager::checkFairness(r2)) {
        s2.setState("GREEN"); s1.setState("RED");

        cout << "\n>>> FAIRNESS RULE ACTIVATED <<<\n";
        cout << ">>> GREEN SIGNAL GIVEN TO ROAD 2 <<<\n";

        r2.resetWait(); r1.incrementWait();
    }
    else {
        if (r1.getVehicleCount() > r2.getVehicleCount()) {
            s1.setState("GREEN"); s2.setState("RED");

            cout << "\n>>> HIGH TRAFFIC DETECTED <<<\n";
            cout << ">>> GREEN SIGNAL GIVEN TO ROAD 1 <<<\n";

            r1.resetWait(); r2.incrementWait();
        } else {
            s2.setState("GREEN"); s1.setState("RED");

            cout << "\n>>> HIGH TRAFFIC DETECTED <<<\n";
            cout << ">>> GREEN SIGNAL GIVEN TO ROAD 2 <<<\n";

            r2.resetWait(); r1.incrementWait();
        }
    }

    display();
}

void TrafficController::display() {
    cout << "\n=====================================\n";
    cout << "       TRAFFIC SYSTEM STATUS\n";
    cout << "=====================================\n";

    cout << "\n[ ROAD STATUS ]\n";
    cout << "Road 1 Vehicles : " << r1.getVehicleCount() << endl;
    cout << "Road 2 Vehicles : " << r2.getVehicleCount() << endl;

    cout << "\n[ SIGNAL STATUS ]\n";
    cout << "Signal 1 : " << s1.getState() << endl;
    cout << "Signal 2 : " << s2.getState() << endl;

    cout << "=====================================\n";
}
