#include <iostream>

using namespace std;

class account{
    private:
        int amount;
        static int number;
    public:
        account() {
            cout << "default" << endl;
            number++;
        }

        // account (int a) {
        //     amount = a;
        // }

        // is the same as

        account(int a):amount(a) {
            cout << "second constructor" << endl;
            number++;
        }

        int getAmount() {
            return amount;
        }

        static int getNumber() {
            return number;
        }

};

int account::number = 0;

int operator+(account a, account b) {
    int amountA = a.getAmount();
    int amountB = b.getAmount();
    return amountA + amountB;
} // Overloaded the + operator

int main() {
    account james(200);
    account kelly(700);

    cout << "----------------------------------" << endl;

   // OVERLOADING OPERATORS

    int total = james + kelly;
    cout << total << endl; // takes james.getamount and kelly.getamount and adds them based on the overloaded operator
   // in order to call the overloaded operator, a class must be involved or it will use the normal + operator

    return 0;
}