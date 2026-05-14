#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void calculateSeries() {
    int n;
    double sum = 0, resistor;
    cout << "\n--- Series Resistance ---" << endl;
    cout << "Enter the number of resistors: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter resistance for R" << i + 1 << " (ohms): ";
        cin >> resistor;
        sum += resistor;
    }
    cout << "Total Series Resistance: " << sum << " ohms" << endl;
}

void calculateParallel() {
    int n;
    double reciprocalSum = 0, resistor;
    cout << "\n--- Parallel Resistance ---" << endl;
    cout << "Enter the number of resistors: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter resistance for R" << i + 1 << " (ohms): ";
        cin >> resistor;
        if (resistor == 0) {
            cout << "Warning: Resistance cannot be zero in parallel. Skipping..." << endl;
            continue;
        }
        reciprocalSum += (1.0 / resistor);
    }

    if (reciprocalSum == 0) {
        cout << "Total Parallel Resistance: 0 ohms" << endl;
    } else {
        cout << "Total Parallel Resistance: " << (1.0 / reciprocalSum) << " ohms" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===============================" << endl;
        cout << "  Circuit Resistance Calculator" << endl;
        cout << "===============================" << endl;
        cout << "1. Series Circuit" << endl;
        cout << "2. Parallel Circuit" << endl;
        cout << "3. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1: calculateSeries(); break;
            case 2: calculateParallel(); break;
            case 3: cout << "Exiting... Goodbye!" << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}