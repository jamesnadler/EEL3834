#include <iostream>

using namespace std;

int sumNormal(int n) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum = sum+i;
    }
    // same as sum(4) = 4+sum(3); sum(3) = 3+sum(2); etc.. can use recursion
    return sum;
}

int sumRecursion(int n) {
    if (n == 0) {
        return 0;
    } // if this isn't here, the function wont work bc it keeps adding negative numbers

    else {
    return n + sumRecursion(n-1);
    }
    // stops at sum(1) due to if statement
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int handshake(int n) {
    if (n<=1) {
        return 0;
    }
    else {
        return (n-1) + handshake(n-1);
    }
}

int main() {

    // recursion is the act of a function calling itself

    cout << sumNormal(4) << endl;
    cout << sumRecursion(4) << endl;
    cout << factorial(4) << endl;
    cout << handshake(4) << endl;



    return 0;
}
