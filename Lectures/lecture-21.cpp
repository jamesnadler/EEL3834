#include <iostream>

using namespace std;

class account {
    private:
        int amount;
        int *password; // stores the addres of an int allocated on heap
    public:
        account() {
            amount = 0;
            password = nullptr; // no heap memory yet - nullptr means "points to nothing"
            cout << "default constructor" << endl;
        }
        account(int a, int p):amount(a), password (new int(p)) { // the keyword new allocates one int on the heap and stores p in it
            cout << "overloaded constructor" << endl;
        }
        account(const account & other) { // this is a copy constructor
            this->amount = other.amount; // the -> operator points to itself. basically . operator for pointers.

            if (other.password != nullptr) {
                this->password = new int(*other.password);
            }
            else {
                this->password = nullptr;
            }
        }
        ~account() { // this is a destructor, signified by ~
            delete password; // frees up memory space
            password = nullptr;
            cout << "destructor" << endl;
        }

};

int main() {




    return 0;
}