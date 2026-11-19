#include <iostream>
#include <cmath> // i included this library for the abs() function
#include <iomanip> // i included this library to format the output to 2 decimal places

using namespace std;

// here i am prototyping my functions before the program runs

bool isValidResistance(double resistance);

double calculateAverage(double resistance1, double resistance2);

double calculateAverage(double resistance1, double resistance2, double resistance3);

void calculateBounds(double nominalResistance, double& lowerBound, double& upperBound, double tolerancePercent = 5.0);

double calculatePercentError(double nominalResistance, double averageResistance);

int main() {

    string repeat; // initializing input character for code repeat

    cout << "Welcome to the Resistor Measurement Analyzer!" << endl;

    do {
    cout << endl;

    double nominal_resistance;

    while (true) { // creates an infinite loop until a valid nominal resistance is entered
        cout << "Enter nominal resistance in ohms: ";
        cin >> nominal_resistance;

        if (isValidResistance(nominal_resistance) == 0) { // uses function isValidResistance to determine if the inputted nominal resistance is valid
            cout << "Invalid resistance! Resistance must be greater than 0." << endl; // output if nominal_resistance is not greater than 0
        }
        else {
            break;
        }
    }
    
    int input_number;

    while (true) { // creates an infinite loop until the user enters 2 or 3
        cout << "How many measurements would you like to analyze (2 or 3): ";
        cin >> input_number;

        if (input_number == 2 || input_number == 3) { // breaks while loop if 2 or 3 is entered
            break;
        }
        else {
            cout << "Invalid choice! Please enter 2 or 3." << endl; // output if not 2 or 3
        }
    }

    double resistance_value;
    double resistance1, resistance2, resistance3;

   
    for (int i=1; i<=input_number; i++) {
        while (true) {
            cout << "Enter resistance measurement " << i << ": "; // asks for an amount of resistance inputs up to the chosen amount of measurements
            cin >> resistance_value;

            if (isValidResistance(resistance_value) == 0) {
                cout << "Invalid resistance! Resistance must be greater than 0." << endl;
            }
            else {
                break;
            }
        }
        if (i == 1) {
            resistance1 = resistance_value;
        }
        else if (i == 2) {
            resistance2 = resistance_value;
        }
        else if (i == 3) {
            resistance3 = resistance_value;
        } // this block assigns the inputted values to resistance values 1-3
    }

    double average_resistance;

    if (input_number == 2) {
        average_resistance = calculateAverage(resistance1, resistance2);
    }
    else if (input_number == 3) {
        average_resistance = calculateAverage(resistance1, resistance2, resistance3);
    } // this block chooses which overloaded function to use based on input parameters

    double upper_bound, lower_bound;

    calculateBounds(nominal_resistance, lower_bound, upper_bound);

    double percent_error = calculatePercentError(nominal_resistance, average_resistance);

    string resistor_status;

    if (average_resistance >= lower_bound && average_resistance <= upper_bound) {
        resistor_status = "PASS"; // resistor status passed if average_resistance is between the lower and upper bound
    }
    else {
        resistor_status = "FAIL";
    }

    cout << endl;
    cout << "Resistance Measurement Summary" << endl;
    cout << endl;
    cout << "Nominal Resistance: " << fixed << setprecision(2) << nominal_resistance << " ohms" << endl;
    cout << "Average Measured Resistance: " << fixed << setprecision(2) << average_resistance << " ohms" << endl;
    cout << "Percent Error: " << fixed << setprecision(2) << percent_error << "%" << endl;
    cout << "Acceptable Range: " << fixed << setprecision(2) << lower_bound << " - " << fixed << setprecision(2) << upper_bound << " ohms" << endl;
    cout << "Status: " << resistor_status << endl;
    // this block prints all of the results to the user using setpricision() to format to 2 decimal places

    repeat = "x";

    while (repeat != "y" && repeat != "n" && repeat != "Y" && repeat != "N") {
        cout << endl;
        cout << "Would you like to analyze another resistor? (y/n): ";
        cin >> repeat;
        
        if (repeat != "y" && repeat != "n" && repeat != "Y" && repeat != "N") {
            cout << "Invalid choice! Please enter y or n." << endl;
        }
    } // continues repeating until y or n is entered


    } while (repeat == "y" || repeat == "Y"); // this do while loop repeats only if the user enters 'y' for yes

    cout << endl;
    cout << "Goodbye!" << endl; // output if user enters 'n' for no. ends program.

    return 0;
}

bool isValidResistance(double resistance) { // returns 1 (true) if input resistance is greater than 0 and 0 (false) otherwise
    return resistance > 0;
}

double calculateAverage(double resistance1, double resistance2) { // calculates average of 2 resistance values
    double average = (resistance1+resistance2)/2;
    return average;
}

double calculateAverage(double resistance1, double resistance2, double resistance3) { // overloads above function by adding additional input parameter
    double average = (resistance1+resistance2+resistance3)/3;
    return average;
}

void calculateBounds(double nominalResistance, double& lowerBound, double& upperBound, double tolerancePercent) {
    double tolerance_amount = nominalResistance*(tolerancePercent/100);
    lowerBound = nominalResistance - tolerance_amount;
    upperBound = nominalResistance + tolerance_amount;
}

double calculatePercentError(double nominalResistance, double averageResistance) { // calculates percent error using nominal resistance and calulated average resistance
    double percent_error = (abs(averageResistance-nominalResistance))/(nominalResistance)*100;
    return percent_error;
} // i used the abs() function from cmath to represent the correct formula
