#include <iostream>
#include <cmath>

using namespace std;

class account { // classes are also used to store variables of diff types
   private:
    int amount;
    double rate;
    string name;
    bool indebt = false;

    void inDebt() {
        cout << indebt << endl;
    }

    public:
    void setAmount(int val) {
        amount = val;
    }
    void setAmount(int val, int bonus) {
        amount = val+bonus;
    }
    int getAmount() {
        return amount;
    }
};

class account2 {
    public:
    int amount;
    double rate;
    string name;
};

class point {
    private:
    int x;
    int y;

    public:
    string quadrant;

    void setval(double a, double b) {
        x=a;
        y=b;
    }
    double distance(point a) {
        return sqrt(pow((x-a.x),2) + pow((y-a.y),2)); // sqrt( (x-a.x)^2 - (y-a.y)^2 )
    }
};

int main() {

    account james;
    // you cannot do account james = {200, 2.0, checking} by default
    // you also cannot do james.amount = 0
    // this is because classes default to private! 

    account2 james2 = {200, 2.0, "checking"};
    // this works because i made it public

    james.setAmount(1000);
    cout << james.getAmount() << endl;

    cout << "----------------------------------------------------------" << endl;

    point p1;
    point p2;

    p1.setval(8.0,3.0);
    p2.setval(2.0,4.0);

    cout << p1.distance(p2) << endl;


    return 0;
}