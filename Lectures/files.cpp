#include <iostream>
#include <string>
#include <fstream> // file stream class

using namespace std;

void printhello(ostream &s, string word) {
    s << word;
}

int main() {

    ifstream inputfile; // creating a class instance. "ifstream" is the class for input file stream

    inputfile.open("files_example.txt"); // ifstream class open() member function

    string word;

    inputfile >> word; // reads files_example.txt and stores its string in "word". use getline() to get whole string

    cout << word << endl;

    inputfile.close(); // closes the file and releases it

    cout << "----------------------------------------------------------" << endl;

    ofstream outputfile; // creating a class instance. "ofstream" is the class for output file stream

    outputfile.open("files_example.txt"); 

    outputfile << "this text has been added"; // replaces text in files_example.txt instead of appending it

    outputfile.open("files_example.txt", ios::app); // ios::app allows you to append

    outputfile << "this text has been appended";

    outputfile.close();

    cout << "----------------------------------------------------------" << endl;

    ifstream fakeinput;

    fakeinput.open("nonexistent.txt");

    if (fakeinput.fail()) { // fail() member function tells if you actually connected to a real file
        cout << "failed to open file" << endl;
        // exit(1); // exits the program with error 1
    }

    inputfile.open("files_example.txt");

    char firstchar;
    inputfile.get(firstchar);
    cout << firstchar << endl; // prints first character in accessed file

    inputfile.close();

    cout << "----------------------------------------------------------" << endl;

    cout << "Input file name: ";
    string filename;
    cin >> filename;

    inputfile.open(filename.c_str());
    string sentence;
    getline(inputfile, sentence);

    cout << sentence << endl;

    cout << "----------------------------------------------------------" << endl;

    fstream rwfile ("files_example.txt", ios::in|ios::out);

    string word3;

    rwfile >> word3;

    cout << word3 << endl;

    rwfile << ". this has been added by rwfile" << endl;

    rwfile.seekp(2); // starts writing at the inputted character spot

    rwfile << endl <<  "seekp started this at the 2nd character";

    rwfile.close();




    return 0;
}