#include <iostream>

using namespace std;

int main() {
    int a;
    a = 0b011; // 3 in binary
    int b = 0xF; // 15 in hexadecimal
    cout << sizeof(b) << endl; // prints the size of the variable b in bytes (an int is 4 bytes)

    int c = 8;
    cout << c << endl; // prints 8 (in global scope)
    cout << &c << endl; // prints the memory address of c (global)
    { // these brackets define local scope
        int c = 9; // this is a new variable c that is only accessible within this block
        cout << c << endl; // prints 9 (in local scope)
        cout << &c << endl; // prints the memory address of c (local) - different from the global c
    }
    cout << c << endl; // still prints 8 because out of local scope


    int d = 9;
    d++; // uses increment operator to add 1 to d, making it 10
    cout << d << endl;

    int e = 9;
    int f = 2;
    bool g = e < f; 
    cout << g << endl; // prints 0 (false) because 9 is not less than 2

    int h = 9;
    int i = 7;
    int j = (h>i)?h:i; // uses the ternary operator to assign the value of h to j if h is greater than i
    // otherwise assigns the value of i to j

    return 0;
}