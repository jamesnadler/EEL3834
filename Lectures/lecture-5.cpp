#include <iostream>

using namespace std;

int main() {
    int age = 21;
    int age_limit = 18;
    bool hasID = true;

    if(age >= age_limit) { // uses relational operator >= to check if age is greater than or equal to 18
        cout <<  "You are above the age limit" << endl;
    }

    if (age < age_limit) {
        cout << "You are below the age limit" << endl;
    }

    if (age == age_limit) { // checks if age is the exact same as age_limit
        cout << "You are at the age limit" << endl;
    }

    // OR

    cout << "-----------------------------------------------------" <<endl;

    if((age >= age_limit) && hasID) { // uses relational operator >= to check if age is greater than or equal to 18
        cout <<  "You are above the age limit and have ID" << endl;
        if (age<21) { // checks if age is less than 21, inside of the other if function
            cout << "You cannot buy alcohol" << endl;
        } 
        else {
            cout << "You can buy alcohol" << endl;
        }
    }

    else {
        cout << "You are below the age limit or do not have ID" << endl;
    }

    cout << "-----------------------------------------------------" <<endl;
    
    double a, b, c;
    double x1, x2;
    cout << "Enter the values of the coefficients: ";
    cin >> a >> b >> c;

    double D = pow(b,2) - (4*a*c); // pow function means power (b^2)

    if (D>0){
        x1 = -b + sqrt(D)/(2*a);
        x2 = -b - sqrt(D)/(2*a);
        cout << "has real roots " << x1 << " and " << x2 << endl;
    }
    else if (D==0){
        x1 = -b/(2*a);
        cout << "one root " << x1 << endl;
    }
    else {
        cout << "no real roots" << endl;
    }

    // discrimant of a quadratic

    cout << "-----------------------------------------------------" <<endl;

    int day = 1;

    switch(day) { // alternative to multiple if-else statements
        case 1:
            cout << "Monday" << endl;
            break; // break statement is used to exit the switch statement after a case has been executed
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        default:
            cout << "Not a valid day" << endl;
            
    
    }
    return 0;
}