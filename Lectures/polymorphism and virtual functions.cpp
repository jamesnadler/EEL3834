#include <iostream>

using namespace std;

class A {
    public:
    virtual void eat() { // they keyword virtual allows derived classes to use overwritten functions correctly
        cout << "Class A" << endl;
    } // the base class has access to the derived class if called
};

class B : public A {};

class C : public A {
    public:
    void eat() {
        cout << "Class C" << endl;
    }
};


int main() {

    A a; B b; C c;

    A* ptrA = &a;
    A* ptrB = &b;
    A* ptrC = &c;

    ptrA->eat(); // base class
    ptrB->eat(); // derived class that doesn't overwrite eat(). still says class A without needing to make a new eat() function.
    ptrC->eat(); // derived class that DOES overwrite/redefine eat(). since eat() in A is virtual, prints class C.

    // ALWAYS ONLY use a virtual function in a base class.

    // polymorphism means many forms

    return 0;
}