#include <iostream>

using namespace std;

class account {
    private:
        int amount;
    public:
        account () {

        }
        account(int a) {
            amount = a;
        }

        int getamount() {
            return amount;
        }

        int operator* (account b) {
            return amount * b.getamount();
        }

        int operator()(int val) {
            return amount + val;
        }
        account operator- (account a) {
            account b(a.amount + amount);
            return b;
        } // returns a class instance

        friend int sumaccount(account a, account b);
        friend class bank;

};

class bank {
    public:
        void printamount(account a) {
            cout << a.amount << endl;
        } // can use a.amount (using private info of another class) because the class bank is a friend of account

};

int operator+ (account a, account b) {
    return a.getamount() + b.getamount();
}

int sumaccount(account a, account b) {
    return a.amount + b.amount;
} // since this function is defined as a friend of the class account, it can access its private data

int main() {

    account james(3000), nathan(7000);

    cout << james + nathan << endl; // aka operator+(james, nathan)

    cout << james * 3 << endl;
    // cout << 3 * james << endl;
    // doesn't work because its trying to do 3.operator*(james)

    cout << james(4000) << endl; // will be 7000.
    // overloaded () operator adds input value to getamount()

    cout << "------------------------------------------" << endl;

    account hubert(2000);
    account big;

    big = james - hubert; // will be 5000. james + hubert, using overloaded -

    cout << big.getamount() << endl;


    return 0;
}