#include <iostream>

using namespace std;

class account {
    private:
        int amount;
    public:
        account() {

        }
        account(int a):amount(a) {

        }
        int getamount() {
            return amount;
        }
};


int main() {

    int value = 8;

    // a pointer is a variable that stores the memory location of another variable
    int *pvalue = &value;

    cout << value << endl;
    cout << pvalue << endl; // prints memory address of value
    cout << *pvalue << endl; // prints value
    cout << &pvalue << endl; // prints address of pointer

    cout << "------------------------------------------" << endl;

    int arr[3] = {1,2,3};
    int *a = arr; // stores memory address of first variable of array

    cout << a[0] << endl;
    // is the same as
    cout << *a << endl;

    cout << a << endl; // memory address of virst value
    cout <<a+1<<endl; // address of 2nd value
    cout << *(a+1) << endl; // prints 2

    account james(100);

    account *jamesp = &james; // you can also have a pointer to a class instance

    cout << (*jamesp).getamount() << endl;
    // is the same as
    cout << jamesp->getamount() << endl;
    // which prints the same as
    cout << james.getamount() << endl;
    

    return 0;
}