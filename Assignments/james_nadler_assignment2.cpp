#include <iostream>
#include <iomanip> // i included this library to format the output to 2 decimal places

using namespace std;

int main() {

    char repeat;

    do {
    cout << "Welcome to the Weekly Electricity Usage Calculator!" << endl;
    cout << endl;

    int day_input;
    int day1, day2, day3, day4, day5, day6, day7;

    for (int day=1; day<=7; day++) { // this for loop increments asking for each day's usage until it reaches day 7
        while (true) { // this while loop makes the program keep asking for a single day's usage until a valid input is entered, if invalid
            cout << "Enter electricity usage for Day " << day << ": ";
            cin >> day_input;

            if (day_input < 0 || day_input > 100) { // prints the text if the input is less than 0 or greater than 100, then triggers while loop again
                cout << "Invalid usage! Please enter a value between 0 and 100." << endl;
            }
            else {
                break; // breaks while loop if input is valid, so for loop triggers again
            }
        }

        if (day==1) {
            day1 = day_input;
        }
        else if (day==2) {
            day2 = day_input;
        }
        else if (day==3) {
            day3 = day_input;
        }
        else if (day==4) {
            day4 = day_input;
        }
        else if (day==5) {
            day5 = day_input;
        }
        else if (day==6) {
            day6 = day_input;
        }
        else if (day==7) {
            day7 = day_input;
        }
        // these assign the user input for each day into 7 different variables that can be used for calculations
    }

    double total_usage = day1+day2+day3+day4+day5+day6+day7; // adds all 7 inputs
    double average_usage = total_usage/7; // divides total by 7
    string category;

    if (average_usage<15) {
        category = "Low Usage";
    }
    else if (average_usage >= 15 && average_usage < 30) {
        category = "Moderate Usage";
    }
    else {
        category = "High Usage";
    } // this if else chain classifies the usage category based on the value of average_usage

    cout << endl;
    cout << "Weekly Electricity Usage Summary" << endl;
    cout << endl;
    cout << "Total Usage: " << fixed << setprecision(2) << total_usage << " kWh" << endl;
    cout << "Average Daily Usage: " << fixed << setprecision(2) << average_usage << " kWh" << endl;
    cout << "Usage Category: " << category << endl; // this part is the output to the user, using setpricision() to round to 2 decimal pts

    cout << endl;
    cout << "Would you like to calculate another week? (y/n): ";
    cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y'); // this do while loop repeats only if the user enters 'y' for yes

    cout << "Goodbye!" << endl; // output if user enters 'n' for no

    return 0;
}
