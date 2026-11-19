#include <iostream>
#include <cmath>

using namespace std;

class Mate {
    private:
        string name;
        double humor;
        double kindness;
        double ambition;

        void normalize() {
            double length = sqrt(humor*humor + kindness*kindness + ambition*ambition);

            if (length == 0) {
                name = "Unknown";
                humor = 0.48;
                kindness = 0.6;
                ambition = 0.64;
            }

            {
                humor = humor/length;
                kindness = kindness/length;
                ambition = ambition/length;
            }
        }
    public:
        Mate() {
            name = "Unknown";
            humor = 0.48;
            kindness = 0.6;
            ambition = 0.64;
        }

        Mate(string n, double h, double k, double a) {
            name = n;
            humor = h;
            kindness = k;
            ambition = a;
            normalize();
        }
        
        void setFeatures(double h, double k, double a) {
            humor = h;
            kindness = k;
            ambition = a;
            normalize();
        }

        void printFeatures() {
            cout << humor << endl;
            cout << kindness << endl;
            cout << ambition << endl;
        }
 
        void operator() () {
            cout << name << endl;
        }

        friend double matchScore(Mate a, Mate b);
};

double matchScore(Mate a, Mate b) {
    return a.humor*b.humor + a.kindness*b.kindness + a.ambition*b.ambition;
}

int main() {

    Mate Friend("James", 10, 8.4, 9);
    Mate Friend2("Nathan", -10.3, 2.5, 10);

    cout << matchScore(Friend, Friend2) << endl;

    return 0;
}