#include <iostream>

using namespace std;

struct date { 
    int day;
    int month;
    int year;
};

struct bankAccount {
    string type;
    int amount;
    double interestRate;
    string bankName;
    date creation; // you can put a struct inside a struct

//     void printAccountNumber() {
//         cout << accountNumber << endl;
//     }

// private: // creates values of the struct that can't be accessed
// int accountNumber;

    
};

double printrate (bankAccount a) { // function to print the interestRate value of the struct
    return a.interestRate;
}

int main() {

    bankAccount james; // making a struct named james

    james.type = "checking"; // you do the [struct name].value to store something
    james.amount = 1000;
    james.interestRate = 0.03;
    james.bankName = "PNC";

    // or you can do

    bankAccount matthew = {"savings", 100, 0.01, "Bank of America"};
    // you can also do
    // bankAccount matthew2 = {.amount = 100, .type = "savings", .bankName = "Bank of America", .interestRate = 0.01};
    // if you put the variable types you can do them out of order

    cout << james.type << endl;
    cout << matthew.type << endl;
    // cout << matthew2.type << endl; - commented about because it gave a warning
    // all 3 methods work

    cout << printrate(james) << endl; // prints 0.03

    james.creation = {1,17,2008}; // creation struct inside bankAccount struct

    cout << james.creation.year << endl; // calls the struct in the struct

    // james.accountNumber won't work because it's private
    // james.printAccountNumber(); // will work




    return 0;
}