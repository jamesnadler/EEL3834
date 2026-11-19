#include <iostream>

using namespace std;

class student {
    private:
        string name;
        int *numberOfCourses;
    public:
        student() {
            name = "unknown";
            numberOfCourses = new int(0);
        }
        student(string n, int courses):name(n), numberOfCourses(new int(courses)) {
            
        }
        student(const student &other) { // copy constructor
            name = other.name;
            numberOfCourses = new int(*other.numberOfCourses);
        }
        student& operator=(const student& others) {
            
        }


        void setCourse(int number) {
           *numberOfCourses = number;
        }
        int getCourse() {
            return *numberOfCourses; // numberOfCourses is a pointer, so use * to dereference it
        }
};

int main() {

    // WITHOUT THE COPY CONSTRUCTOR, THIS WILL:
    student s1{"james", 5};
    student s2 = s1; // copies james and the address pointing to 5
    s2.setCourse(20);

    cout << s1.getCourse() << endl; // changing s2 changes s1 because both pointers point to the same place
    cout << s2.getCourse() << endl;
}