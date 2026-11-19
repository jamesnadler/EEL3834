#include <iostream>

using namespace std;

class account {
    private:

    int amount;
    double rate;
    string type;
    string bank;
    int password;
    static int numberOfAccounts;

    public:

    void addAmount(int val) {
        amount = amount + val;
    }

    bool subtractAmount(int val, int p) {
        if((password==p) && (amount>val)) {
            amount = amount - val;
            return true;
        }
        else {
            return false;
        }
    }

    int getAmount(); // you can declare a function in a class then define it later

    account() { // This is a constructor. It has the same name as the class.
        cout << "New account created" << endl;
        numberOfAccounts++;
    } // whenever you make a new instance of the class, the constructor runs
    // in this case it prints out new account created

    account(int a, double r, string t, string b, int p) { // you can overload constructors
        cout << "New account created with values" << endl;
        amount = a;
        rate = r;
        type = t;
        bank = b;
        password = p;
        numberOfAccounts++;
    } // this is a constructor that takes parameters and stores them in the class

    void sendAmount(account &reciever, int amount, int password) {
        if (subtractAmount(amount, password)) {
            reciever.addAmount(amount);
        }
        else {
            cout << "Wrong Password or invalid send amount. Your transaction has been cancelled." << endl;
        }
    }

    static int getNumUsers() { // you can also have static functions
        return numberOfAccounts;
    } // a static function allows you to access private static variables

};

int account::numberOfAccounts; // you have to define a static variable outside of a class for it to work

int main() {
    
    account james1;

    account james(1000, 5, "savings", "PNC", 3690);
    cout << james.getAmount() << endl; // prints 1000

    account nathan(100, 5, "spend", "BoA", 123);

    james.sendAmount(nathan, 100, 3690); // will work
    cout << "----------------------------------" << endl;
    james.sendAmount(nathan, 1000000000, 3690); // wont work

    cout << "James now has " << james.getAmount() << endl;
    cout << "Nathan now has " << nathan.getAmount() << endl;

    cout << "----------------------------------" << endl;

    cout << account::getNumUsers() << endl;


    return 0;
}

int account::getAmount() {
    return amount;
}