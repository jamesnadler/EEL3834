#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char name[6] = {'j', 'a', 'm', 'e', 's', '\0'}; 
    // this is a c-string
    // \0 is called the null character
    char name1[7] = "james"; // same thing

    // you can't completely change the value of a c-string
    // ex. you can't do name1 = "albert" after already initializing name1

    int number[3] = {1,3,4};

    cout << number << endl; // prints memory address
    cout << name << endl; // prints james. aka the whole content of the char array

    cout << "------------------------------------------" << endl;

    char word1[60] =  "hello";
    char word2[70] = "goodbye";

    cout << "strcpy" << endl;

    strcpy(word1, word2); // copies value of word2 into word1

    cout << word1 << " " << word2 << endl; // prints goodbye goodbye

    cout << "------------------------------------------" << endl;

    cout << "strcat" << endl;

    strcat(word1,word2); // joins both strings
    // strcat(target_string_var, src_string, limit)
    cout << word1 << endl;

    cout << "------------------------------------------" << endl;

    cout << "strlen" << endl;

    char word3[60] = "computer";
    cout << strlen(word3) << endl; // returns character length of a c-string

    // spaces count
    char word4[60] = "hello world";
    cout << strlen(word4) << endl; // 11 characters w/ the space

    cout << "------------------------------------------" << endl;

    cout << "strcmp" << endl;

    cout << strcmp(word3, word4) << endl; // returns 0 if both strings are the same, negative otherwise
    // compares using ASCII values
    // basically does the difference of the ASCII values of word3-word4

    cout << "------------------------------------------" << endl;

    char input[20];

    cin.getline(input, 20); // takes up to 20 characters of the input
    // reads the whole line, including spaces
    // if you don't do this, cin will only read a word -> IMPORTANT FOR ASSIGNMENTS
    // use simply .get() for chars
    
    cout << input << endl;

    return 0;
}