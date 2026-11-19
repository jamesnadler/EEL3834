#include <iostream>

using namespace std;

int main () {
    int numbers[4] = {1,3,4,5}; // array of integers

    for (int i=0; i<=3; i++) {
        cout << numbers[i] << endl; // starting at numbers[0], prints numbers[i+1] until i <= 3
    }

    cout << "-----------------------------------------------------" <<endl;

    int numbers_2[4] = {1,3,4,5};
    int sum = 0;

    for (int i=0; i<=3; i++) {
        sum = sum + numbers_2[i];
    }

    cout << sum << endl; // prints the sum of the numbers in the array

    cout << "-----------------------------------------------------" <<endl;

    int A[2][2] = {{1,3},{1,3}};

    for (int rows=0; rows<2; rows++) {
        for (int col=0; col<2; col++) {
            cout << A[rows][col] << " " << endl;
        }
        cout << endl;
    }

    cout << "-----------------------------------------------------" <<endl;

    int y = 1;

    while(y<12) {
        cout << "hello";
        
        y++; // this causes it to print hello 11 times. if this is not here, it will go forever
    }
    cout << endl;

    cout << "-----------------------------------------------------" <<endl;

    int num = 2;
    int guess;

    while(true) {
        cout << "Guess the number: ";
        cin >> guess;

        if (guess==num) {
            cout << "You got the number!" << endl;
            break;
        }
        else if(guess<num) {
            cout << "Your number is lower!" << endl;
        }
        else {
            cout << "Your number is higher!" << endl;
        }

    }

    cout << "-----------------------------------------------------" <<endl;

    int x = 3;

    do {
    cout << x << endl;
    x--;
    } while(x>2); // prints x while x>2, so only prints once because of the -- increment

    return 0;
}