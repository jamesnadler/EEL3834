#include <iostream>

using namespace std;

int subtract(int val1, int val2) {
    return val1-val2;
}

int add(int val1, int val2) {
    int sum = val1+val2;
    const int c = 1;
    return subtract(sum,c); // you can call a function in a function
    // returns 1 less than the value of the sum sum - c = sum - 1
}

int greater5orlessthan2(int a) {
    if (a>5) {
        return a*2;
    }
    else if(a<2) {
        return a*5;
    }
    else {
        return 0;
    }
}

int countplayers() {
    static int number = 0;
    number = number+1;
    return number;
}

bool adult(int age) { // functions can be bools
    return age>18;
}

void hello(string name) { // using void because no return value. only prints something
    cout << "Hello, " << name << endl;
}

int main() {
    const int a = 9; // const means constant. this is now read-only and can't be changed
    // a = 10; won't work - program errors
    cout << a << endl;

    cout << "----------------------------------------------------------" << endl;
    
    int b = 7;
    int c = 2;
    int d = add(b,c);
    cout << d << endl;

    cout << "----------------------------------------------------------" << endl;
    
    int q = 4;
    cout << greater5orlessthan2(q) << endl; // returns 0 because triggers else condition of called function

    cout << "----------------------------------------------------------" << endl;

    cout << countplayers() << endl;
    cout << countplayers() << endl;
    cout << countplayers() << endl;
    // if static were not present in the function, this would print 1 1 1
    // the variable number's lifespan outlasts its scope

    cout << "----------------------------------------------------------" << endl;

    int age = 9;
    cout << adult(age) << endl; // prints 0 (false) because 9<18
    
    cout << "----------------------------------------------------------" << endl;

    string name = "James";
    hello(name);

    cout << "----------------------------------------------------------" << endl;

    static int x = 0;
    x+=2; // the += operator adds the number to the right onto the variable on the left

    cout << x << endl;
    
    return 0;
}