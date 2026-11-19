#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b) {
    return a+b;
} // alternative to overloading functions, this template function can be used to add two values of any data type

struct student {
    int age;
    string year;
    string name;
};

int main () {

    int numbers[5] = {5,3,8,2,4};
    for (int i=0; i<(5-1); i++) {
        for (int j=0; j<(5-1); j++) {
            if (numbers[j]>numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers [j+1] = temp;
            }
        }
    } // this block of code sorts the array numbers[] in ascending order using bubble sort
    // bubble sort works by comparing adjacent elements in the array and swapping them if they are in the wrong order. This process is repeated until the entire array is sorted.

    for (int i=0; i<5; i++) {
        cout << numbers[i] << " ";
    }

    cout << endl;
    cout << "----------------------------------------------------------" << endl;

    int list[5] = {5,3,8,2,4};
    int target = 11;

    for (int i=0; i<5; i++) {
        if (list[i] == target) {
            cout << "Found target at index " << i << endl;
            break;
        }
        else {
            cout << "Target not found" << endl;
        }
    } // searches through the array for the target value and prints its index if found

    cout << "----------------------------------------------------------" << endl;

    int a = 9;
    int b = 8;

    double c = 2.4;
    double d = 3.6;

    cout << add(a,b) << endl;
    cout << add(c,d) << endl;
    // both of these call the template function add() to add two values of different data types

    cout << "----------------------------------------------------------" << endl;

    student one;
    one.name = "James";
    one.age = 18;
    one.year = "Freshman";

    return 0;
}