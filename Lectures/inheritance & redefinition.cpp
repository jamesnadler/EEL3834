#include <iostream>
#include <typeinfo>

using namespace std;

class Employee { // base class
    public:
        Employee() {
            cout << "employee constructor" << endl;
        }
        Employee(string newName, int newSsn) {
            name = newName;
            ssn = newSsn;
        }
        ~Employee() {
            cout << "employee destructor" << endl;
        }
        string getName( ) {
            return name;
        }
        int getSsn() {
            return ssn;
        }
        void setName(string newName) {
            name = newName;
        }
        void setSsn(int newSsn) {
            ssn = newSsn;
        }
        void print() {
            cout << "Employee Information" << endl;
            cout << "--------------------" << endl;
            cout << "Name: " << name << " - SSN: " << ssn << endl;
        }
    protected:
        string name;
        int ssn;
};


class UFemployee : public Employee { // derived class
    public:
        UFemployee() {
            cout << "UFemployee constructor" << endl;
            name = "";
        }
        UFemployee(string name, int newID, int newSsn): Employee(name, newSsn) {
            ufID = newID;
        }
        ~UFemployee() {
            cout << "UFemployee destructor" << endl;
        }
        int getUFID() {
            return ufID;
        }
        void setUFID(int newID) {
            ufID = newID;
        }
        void print() { // overwriting (aka redefining) the print() function from Employee class, completely changing it
            cout << "University of Florida Employee Information" << endl;
            cout << "------------------------------------------" << endl;
            cout << "Name: " << name << " - SSN: " << ssn << " - UFID: " << ufID << endl;
        } // this is different from overloading. signature doesn't matter.
    private:
        int ufID;
};


int main() {

    // inheritance is a mechanism where a new class (a derived/child class) is created based on an existing class
    // this allows the derived class to inherit properities and behaviors from its base class

    // a base class is a "general" class from which others derive

    // a derived class automatially has its base class's member variables and functions


    // "protected" members are publicly accessible by another inherited class, but are private to other classes/code

    UFemployee ufEmp("James Nadler", 72444686, 123);

    Employee *emp = &ufEmp; // a UFemployee is also an Employee

    cout << "Name: " << ufEmp.getName() << " SSN: " << ufEmp.getSsn() << " UFID: " << ufEmp.getUFID() << endl;
    cout << "Name: " << emp->getName() << " SSN: " << emp->getSsn() << " UFID: " << ((UFemployee *)emp)->getUFID() << endl;

    cout << "----------------------------------" << endl;

    cout << "ufEmp Type:" << typeid(ufEmp).name() << endl;
    cout << "emp Type: " << typeid(emp).name() << endl;
    cout << "*emp Type: " << typeid(*emp).name() << endl;
    cout << endl;

    ufEmp.print(); // is able to print protected info from parent class. this is an overwritten function.
    cout << endl;
    ufEmp.Employee::print(); // uses original print function

    cout << endl;

    return 0;
}