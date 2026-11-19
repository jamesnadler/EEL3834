#include <iostream>
#include <iomanip> // i included this library to format the output to 2 decimal places

using namespace std;

int main () {
    double voltage;
    double resistance;

    cout << "Enter voltage in volts: ";
    cin >> voltage;
    cout << "Enter resistance in ohms: ";
    cin >> resistance;

    double power = (voltage * voltage) / resistance;

    cout << endl;
    cout << "--- Resistor Power Summary ---" << endl;
    cout << "Voltage: " << voltage << " volts" << endl;
    cout << "Resistance: " << resistance << " ohms" << endl;
    cout << "Power: " << fixed << setprecision(2) << power << " watts" << endl;

    return 0;
}

