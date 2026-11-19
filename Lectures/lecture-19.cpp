#include <iostream>
#include <cstring>
#include <cctype> // for toupper and tolower
#include <string>

using namespace std;

int main() {

    char name[6] = {'j', 'a', 'm', 'e', 's', '\0'}; 
    char name2[6] = "james";

    // if you do
    char word[6] = {'h','e', '\0','l','l','o'};
    cout << word << endl; // only prints he


    char word1[60];
    char word2[60];

    cin >> word1; 
    cin.getline(word2,60);
    cout << word1 << endl;
    // whatever you enter into word1 leaves \n in the input buffer, and the next line reads that as its input, skipping the 2nd input

    cout << "------------------------------------------" << endl;

    cin >> word1;
    cin.ignore();
    cin.getline(word2,60);
    // fixes previous problem, ignore() allows for 2nd input

    cout << "------------------------------------------" << endl;

    char ch = 'p';
    cout << ch << endl;

    ch = toupper(ch); // makes ch Uppercase
    cout << ch << endl;

    ch = tolower(ch); // makes ch Lowercase
    cout << ch << endl;

    // toupper and tolower return ASCII values

    char ch1 = 66;
    cout << (char)toupper(ch1) << endl;
    // takes ASCII 66 and makes it uppercase (lowercse b to B)

    cout << "------------------------------------------" << endl;

    // string class

    string s = "this is a string";
    s = "this is the same variable but a new string";
    // you can change a class string without worrying about size

    cout << s.length() << endl; // prints length of string s

    int index1 = s.find("this");
    int index2 = s.find("is");
    cout << index1 << endl; // prints 0
    cout << index2 << endl; // prints 2

    s[0] = 'p'; // you can still change specific characters
    cout << s << endl;

    s[100] = 'j'; // still works but out of range so nothing happens
    cout << s << endl;

  //  s.at(100) = 'p'; // same as above but gives error if out of range


    int i;
    i = stoi(s); // stoi() is string to integer
    cout << i << endl;


    return 0;
}