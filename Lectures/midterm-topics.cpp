#include <iostream>

using namespace std;

class student {
    private:
        int age;
        string course;
    public:
        student() {
        
        }
        student(int a, string c) {
            age = a;
            course = c;
        }
        int getage() {
            return age;
        }
        void setage(int a) {
        }
        string getcourse() {
            return course;
        }
};

class teacher {
    private:
        int age;
        string course;
    public:
        teacher() {
        
        }
        teacher(int a, string c) {
            age = a;
            course = c;
        }
        int getage() {
            return age;
        }
        void setage(int a) {
        }
        string getcourse() {
            return course;
        }
};

bool sameCourse(student s, teacher t) {
    return s.getcourse() == t.getcourse();
}

int main() {

    // frq:
    // q1 - 2's complement or similar
    // q2 - return types, input types (function declaration)
    // q3 - loops, if/else, 
    // q4 - classes

    // reference sheet: operator precendence, no full questions from quizzes

    // multiple choice:
    // steps of converting high level language to machine code
    // post-increment and pre-increment
    // switch case
    // keywords break & continue
    // functon declaration vs description
    // return type IS NOT part of function signature: only input types, input count, and function name
    // static keyword
    // pass by value vs pass by reference
    // row vs column for loop in matrix
    // class vs struct
    // function overloading
    // definitions of a computer, hardware, software, program, high/low level languages, compiler
    // c++ gives you greater memory control than most high level languages
    // 2's complement allows you to present negative numbers
    // fp32 allows you to present floating-point numbers



    // q4 example: create a class called student with 3 private parameters and 2 constructors
    // write a function to get those private parameters
    // do the same for another class called teacher
    // write a function that compares the classes of a student and teacher and see if they match, return true or false
    // example in this file
    

    return 0;
}