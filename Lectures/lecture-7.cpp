#include <iostream>

using namespace std;

int add(int x, int y) {
    int sum = x+y;
    return sum;
} // this is a self-defined function. you must give it a name, a return type, and your inputs

int main() {
    int a = 9;
    int b = 8;
    int sum = add(a,b); // this calls the self-defined add function
    cout << sum << endl; // when you call a function, your inputted variables are copies of the defined inputs in the function itself (in terms of memory location)


}