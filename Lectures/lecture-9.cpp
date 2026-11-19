#include <iostream>
#define pi 3.14 // defines something in the pre-process and doesn't define it in memory (AKA not a variable)
#define square(x) x*x // you can also pre-define functions

using namespace std;

int add(int a, int b) {
    return a+b;
}

int add(double a, int b) {
    cout << "below is the double function" << endl;
    return a+b;
}

////////////////

void swap(int &a, int &b) {
    int temp = a;
    a=b;
    b = temp;
    cout << a << " " << b << endl;
}

int main () {

    int a = 2;
    int b = 9;

    double c = 2;
    int d = 9;

    cout << add(a,b) << endl; // this will choose to use the 1st add function because of its input parameters
    cout << add(c,d) << endl; // this will use the 2nd function

    cout << "----------------------------------------------------------" << endl;

    swap(a,b);

    cout << "----------------------------------------------------------" << endl;
    
    double A = pi*2; // A = 3.14*2 - just a copy-paste
    cout << A << endl;

    int B = square(2); // B = 2*2
    int C = square(2+3); // C = 2+3*2+3 = 11
    
    cout << B << endl;

    return 0;
}