#include <iostream>

using namespace std;

void addone(int val[]) {
    for (int i=0; i<5; i++) {
        val[i] = val[i]+1;
    }
}

void arraysum(int val[], int size) {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum = sum + val[i];
    }
    cout << sum << endl;
}

//////////

void unitvec(double vec[], int size) {
    double squaresum = 0;
    for (int i=0; i<size; i++) {
        squaresum = squaresum + pow(vec[i],2);
    }
    double magnitude = sqrt(squaresum);

    for (int i=0; i<size; i++) {
        vec[i] = vec[i]/magnitude;
    }

}

int main() {
    int numbers[5] = {1,3,5,6,6}; // this is an array

    cout << numbers[0] << endl; // prints the 1st term in the array
    cout << sizeof(numbers) << endl; // prints 20 because each integer is 4 bits. 4x5

    cout << "----------------------------------------------------------" << endl;

    cout << numbers << endl; // memory address of 1st variable
    cout << &numbers[0] << endl; // same thing as above
    cout << numbers+1 << endl; // memory address of 2nd variagble
   
    cout << "----------------------------------------------------------" << endl;

    addone(numbers); // adds 1 to every variable in the array
    cout << numbers[0] << endl; // result after addone() func

    arraysum(numbers,5);

    cout << "----------------------------------------------------------" << endl;

    int matrix[3][2] = {{1,3}, {2,4}, {2,4}};
    // matrix[rows][columns]
    // [1  3]
    // [2  4]
    // [2  4]

    for (int row=0; row<3; row++) {
        for (int col=0; col<2; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }

    cout << "----------------------------------------------------------" << endl;

    int matrix1[3][2] = {{1,3}, {2,4}, {2,4}};
    int matrix2[3][2] = {{1,3}, {2,4}, {2,5}};
    int result[3][2];

    for (int row=0; row<3; row++) {
        for (int col=0; col<2; col++) {
            result[row][col] = matrix1[row][col] + matrix2[row][col]; // result matrix is the sum of both
            cout << result[row][col] << " ";
        }
        cout << endl;
    }

    cout << "----------------------------------------------------------" << endl;

    double vector[3] = {1,3,4};

    unitvec(vector, 3);

    for (int i=0; i<3; i++) {
        cout << vector[i] << " ";
    }

    cout << endl;

    return 0;
}