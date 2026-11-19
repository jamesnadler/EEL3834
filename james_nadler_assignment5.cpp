#include <iostream>
#include <cmath> // included to fix negative complex number display
#include <sstream> // included to check an entire user input, rather than just accepting an int value
#include <string> // included for getline()

using namespace std;

class ComplexNumber {
    private:
        int real;
        int imaginary;
    public:
        ComplexNumber() : real(0), imaginary(0) {
        }
        ComplexNumber(int realValue) : real(realValue), imaginary(0) {
        }
        ComplexNumber(int realValue, int imaginaryValue) : real(realValue), imaginary(imaginaryValue) {
        }
        // these are my 3 constructors, either initializing to zero, only a real value, or both a real and imaginary value.

        void display() const {
            if (imaginary>=0) {
                cout << real << " + " << imaginary << "i"; // prints real + imaginary_i
            }
            else {
                cout << real << " - " << abs(imaginary) << "i"; // takes the absolute value so it doesnt print real - -imaginary_i
            }
        }

        void setValues(int realValue, int imaginaryValue) {
            real = realValue;
            imaginary = imaginaryValue;
        }

        ComplexNumber operator+(const ComplexNumber &other) const { // overloads the + operator, allowing it to add the real and imaginary private variables of 2 ComplexNumber instances
            ComplexNumber addedNumber;
            addedNumber.real = real + other.real;
            addedNumber.imaginary = imaginary + other.imaginary;
            return addedNumber;
        } 

        ComplexNumber operator-(const ComplexNumber &other) const { // overloads the - operator, allowing it to subtract the real and imaginary private variables of 2 ComplexNumber instances
            ComplexNumber subtractedNumber;
            subtractedNumber.real = real - other.real;
            subtractedNumber.imaginary = imaginary - other.imaginary;
            return subtractedNumber;
        }

        friend ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second);
        friend bool operator==(const ComplexNumber& first, const ComplexNumber& second);
        // makes these 2 overloaded operators friends, so they can access private ComplexNumber variables
        
};

ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second);

bool operator==(const ComplexNumber& first, const ComplexNumber& second);

int isValidComponent(string question);

int isValidMenuOption(string question);

int isValidUpdateSelection(string question);

// declaring non-member functions

int main() {

    cout << "Welcome to the Complex Number Calculator!" << endl;
    cout << endl;

    ComplexNumber result;
    ComplexNumber one(1);
    // objects created using default and single-parameter constructor
    // result is used for storing menu calculations

    int realA;
    int imaginaryA;
    int realB;
    int imaginaryB;

    realA = isValidComponent("Enter the real component of Number A: ");

    imaginaryA = isValidComponent("Enter the imaginary component of Number A: ");

    realB = isValidComponent("Enter the real component of Number B: ");

    imaginaryB = isValidComponent("Enter the imaginary component of Number B: ");

    // uses isValidComponent() to get the real and imaginary components for both number A and B

    ComplexNumber numberA(realA, imaginaryA);
    ComplexNumber numberB(realB, imaginaryB);

    // creates the 2 complex numbers using values from before

    int choice;

    do { // keeps displaying the menu until the user chooses to exit

        cout << endl;
        cout << "--- Complex Number Calculator Menu ---" << endl;
        cout << "1. Display both complex numbers" << endl;
        cout << "2. Add the numbers" << endl;
        cout << "3. Subtract Number B from Number A" << endl;
        cout << "4. Multiply the numbers" << endl;
        cout << "5. Check whether the numbers are equal" << endl;
        cout << "6. Update a complex number" << endl;
        cout << "7. Exit" << endl;

        choice = isValidMenuOption("Enter your choice: ");

        if (choice == 0) { // isValidMenuOption() returns 0 if there is an error. this then continues, restarting the do-while loop
            continue;
        }

        switch(choice) { // performs the appropriate choice based on the user's input
            case 1: // displays both complex numbers
                cout << endl;
                cout << "Number A: ";
                numberA.display();

                cout << endl;
                cout << "Number B: ";
                numberB.display();

                cout << endl;
                break;

            case 2: // uses overloaded + to add both complex numbers
                cout << endl;
                result = numberA + numberB;

                cout << "Sum: ";
                result.display();
                cout << endl;
                break;

            case 3: // uses overloaded - to subtract complex numbers
                cout << endl;
                result = numberA - numberB;

                cout << "Difference (A - B): ";
                result.display();
                cout << endl;
                break;

            case 4: // uses overloaded * to multiply complex numbers
                cout << endl;
                result = numberA * numberB;

                cout << "Product: ";
                result.display();
                cout << endl;
                break;

            case 5: // uses overloaded == to check equality
                cout << endl;

                if (numberA == numberB) {
                    cout << "The complex numbers are equal." << endl;
                }
                else {
                    cout << "The complex numbers are not equal." << endl;
                }
                break;

            case 6: // allows user to update previously entered complex numbers
                cout << endl;

                int updateChoice = isValidUpdateSelection("Which number would you like to update? (1 = A, 2 = B): ");
                // uses isValidUpdateSelection(), specified to 1 or 2
            
                int newRealComponent = isValidComponent("Enter the new real component: ");
                int newImaginaryComponent = isValidComponent("Enter the new imaginary component: ");
                // uses isValidComponent() just like before
                
                if (updateChoice == 1) { // updates number A if choice is 1
                    numberA.setValues(newRealComponent, newImaginaryComponent);
                    cout << "Number A updated." << endl;
                }
                else if (updateChoice == 2) { // updates number B if choice is 2
                    numberB.setValues(newRealComponent, newImaginaryComponent);
                    cout << "Number B updated." << endl;
                }
                break;
        }

    } while (choice != 7); // ends do-while loop if user chooses 7 to exit

    cout << endl;
    cout << "Good Bye!" << endl;

    return 0;
}

ComplexNumber operator*(const ComplexNumber& first, const ComplexNumber& second) { // overloads the * operator, allowing it to multiply the real and imaginary private variables of 2 ComplexNumber instances
         ComplexNumber multipliedNumber;
         multipliedNumber.real = (first.real * second.real) - (first.imaginary * second.imaginary); 
         multipliedNumber.imaginary = (first.real * second.imaginary) + (first.imaginary * second.real);
         // using provided formula
         return multipliedNumber;
        }

bool operator==(const ComplexNumber& first, const ComplexNumber& second) { // overloads the == operator, allowing it to check if the real and imaginary private variables of 2 ComplexNumber instances are equal
    return (first.real == second.real) && (first.imaginary == second.imaginary);
}

int isValidComponent(string question) { // Allows for inputted component validation with the simple input of what question you want to prompt the user with
    string input;
    int value;
    char extra;
    
    while (true) { // keeps asking for input until the user enters a valid component
        cout << question;
        getline(cin, input);

        stringstream ss(input);

        if (!(ss >> value)) { // checks if input is an integer, rejects if not
            cout << "Invalid input! Please enter an integer between -100 and 100." << endl;
            continue;
        }
        if (ss >> extra) { // checks if there's any extra characters after the integer
            cout << "Invalid input! Please enter an integer between -100 and 100." << endl;
            continue;
        }
        if (value > 100 || value < -100) { // checks if the input is between -100 and 100
            cout << "Invalid input! Please enter an integer between -100 and 100." << endl;
            continue;
        }

        return value; // returns inputted value if valid
    }
}

int isValidMenuOption(string question) { // Fundamentally the same as above function, just with a different range specialized for the menu options
    string input;
    int value;
    char extra;
    
    cout << question;
    getline(cin, input);

    stringstream ss(input);

    if (!(ss >> value)) { // checks if input is an integer, rejects if not
        cout << "Invalid choice! Please enter an integer between 1 and 7." << endl;
        return 0;
    }
    if (ss >> extra) { // checks if there's any extra characters after the integer
        cout << "Invalid choice! Please enter an integer between 1 and 7." << endl;
        return 0;
    }
    if (value > 7 || value < 1) { // checks if the input is between 1 and 7
        cout << "Invalid choice! Please enter an integer between 1 and 7." << endl;
        return 0;
    }

    return value;
}

int isValidUpdateSelection(string question) { // Another input validation, this time checking for 1 or 2 for updating complex numbers
    string input;
    int value;
    char extra;

    while (true) {
        cout << question;
        getline(cin, input);

        stringstream ss(input);

        if (!(ss >> value)) { // checks if input is an integer, rejects if not
            cout << "Invalid selection! Please enter 1 or 2." << endl;
            continue;
        }
        if (ss >> extra) { // checks if there's any extra characters after the integer
            cout << "Invalid selection! Please enter 1 or 2." << endl;
            continue;
        }
        if (value != 1 && value != 2) { // checks if the input is 1 or 2
            cout << "Invalid selection! Please enter 1 or 2." << endl;
            continue;
        }

        return value;
    }
}