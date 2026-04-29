#include <iostream>
#include "TrafficController.h"

using namespace std;

int main() {
    TrafficController t;
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << "      SMART TRAFFIC SIMULATOR\n";
        cout << "=====================================\n";
        cout << "1. Start Simulation\n";
        cout << "2. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        if (choice == 1) {
            t.inputTraffic();
            t.controlTraffic();
        }

    } while (choice != 2);

    return 0;
}
