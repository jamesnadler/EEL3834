#include <iostream>

using namespace std;

int main() {
    int a = 3; // 011 in binary
    int b = a<<1; // (0110 = 6) left shift operator shifts the bits of a to the left by 1 position, effectively multiplying it by 2
    int c = a<<2; // 2 positions (1100 = 12)

    cout << b << endl;
    cout << c << endl;

    cout << "-----------------------------------------------------" <<endl;

    int d = 4;
    int e = 2;
    bool f = (d % e) == 0; // checks if d is divisible by e (4%2==0), which is true, so f is assigned the value true (1)
    cout << f << endl;

    cout << "-----------------------------------------------------" <<endl;

    char grade = 'A';
    cout << grade << endl; // prints A
    cout << int(grade) << endl; // A is 65 in ASCII, so this prints 65

    string name = "James";
    cout << name << endl; // prints James

    cout << "-----------------------------------------------------" <<endl;

    int g, h, i;
    cout << "enter the value of g, h, and i: ";
    cin >> g >> h >> i; // asks user for 3 separate inputs separated by spaces
    cout << g << " " << h << " " << i << endl;


    cout << "-----------------------------------------------------" <<endl;

    return 0;
}