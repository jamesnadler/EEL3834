#include <iostream>

namespace A{
    double g = 9.8;
}

int main() {
    std::cout << A::g << std::endl; // calls the namespace A and prints the value of g

// or

    using namespace A;
     std::cout << g << std::endl; // same as above but prevents you from needing to call namespace A every time
   

    int age{9}; // initialization of an integer variable. prevents you from neededing to declare variable first 
    // and then assign it a value

    int a = 3;
    int b = 2;
    int c = a/b; // division of two integers. the result will be an integer despite being a float (in this case 1)
    // since it is pre-defined as an integer
    float d = a/b;
    std::cout << c << std::endl;
    std::cout << d << std::endl;

    bool lightOn = 1;
    bool lightOff = 0;
    std::cout << lightOn << std::endl;
    std::cout << lightOff << std::endl; // booleans are true or false
    // 1 - true, 0 - false

    char grade = 'A';
    std::cout << grade << std::endl; // char is a single character.

    int numbers[3]; // this is an array, in this case of integers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    std::cout << numbers[0] << std::endl; // prints the first element of the array, which is 1
    std::cout << numbers[1] << std::endl; // prints the second element of the array, which is 2
    std::cout << numbers[2] << std::endl; // prints the third element of the array, which is 3

    double l;
    double w;
    double area;
    std::cin >> l; // cin asks for user input and stores it in the variable l
    std::cin >> w;
    area = l * w;
    std::cout << area << std::endl; // this is how you take in user input and print it out

# include <cmath>

     return 0;
}

int add(int number1, int number2) {
    return number1 + number2; // this is a defined function that takes in two integers and returns their sum
}