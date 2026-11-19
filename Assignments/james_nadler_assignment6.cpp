#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

bool isValidPhrase(const string& phrase);

char* normalizePhrase(const string& phrase);

void countLetters(const char* phrase, int* frequencies);

bool areAnagrams(const int* firstCounts, const int* secondCounts);

int main() {

    cout << "Welcome to the Anagram Checker!" << endl;
    cout << endl;

    string firstPhrase, secondPhrase;

    while (true) {
        cout << "Enter the first phrase: ";
        getline(cin, firstPhrase);
        if (isValidPhrase(firstPhrase) == true) {
            break;
        }
        cout << "Invalid input! Enter 1-100 characters with at least one English letter." << endl;
    }

    while (true) {
        cout << "Enter the second phrase: ";
        getline(cin, secondPhrase);
        if (isValidPhrase(secondPhrase) == true) {
            break;
        }
        cout << "Invalid input! Enter 1-100 characters with at least one English letter." << endl;
    }

    // both loops repeatedly prompt the user until a valid phrase is entered

    char* normalizedFirst = normalizePhrase(firstPhrase);
    char* normalizedSecond = normalizePhrase(secondPhrase);
    // initializing the 2 normalized phrases by calling the normalizePhrase() function


    cout << endl;
    cout << "Original phrase 1: " << firstPhrase << endl;
    cout << "Original phrase 2: " << secondPhrase << endl;
    cout << "Normalized phrase 1: " << normalizedFirst << endl;
    cout << "Normalized phrase 2: " << normalizedSecond << endl;
    cout << "Letter count 1: " << strlen(normalizedFirst) << endl;
    cout << "Letter count 2: " << strlen(normalizedSecond) << endl; // strlen used because the normalized strings are c-strings

    int* firstCounts;
    int* secondCounts;

    firstCounts = new int[26]; 
    secondCounts = new int[26];
    // dynamically allocates two integer arrays with 26 elements each to store letter frequencies

    countLetters(normalizedFirst, firstCounts);
    countLetters(normalizedSecond, secondCounts);
    // counts the amount of each type of letter in the 2 normalized phrases

    if (areAnagrams(firstCounts, secondCounts) == true) {
        cout << "The phrases are anagrams." << endl;
    }
    else {
        cout << "The phrases are not anagrams." << endl;
    }
    
    delete[] normalizedFirst;
    delete[] normalizedSecond;
    delete[] firstCounts;
    delete[] secondCounts;
    // frees up allocated space in memory for these arrays

    normalizedFirst = nullptr;
    normalizedSecond = nullptr;
    firstCounts = nullptr;
    secondCounts = nullptr;
    // sets all 4 pointers to nullptr after their dynamically allocated arrays have been deleted

    cout << endl;

    cout << "Good Bye!" << endl;

    return 0;
}

bool isValidPhrase(const string& phrase) {
    if (1 <= phrase.size() && phrase.size() <= 100) { // checks if the size of the string phrase is between 1 and 100
        for (int i=0; i<phrase.size(); i++) { // loops through characters in phrase
            if (isalpha(phrase[i])) { // if the character at phrase[i] is a english letter, returns true
                return true;
            }
        }
    }
    return false;
}

char* normalizePhrase(const string& phrase) {
    int letterCount = 0;
    for (int i=0; i<phrase.size(); i++) {
        if (isalpha(phrase[i])) {
                letterCount++;
            }
    } // increments letterCount when an english letter is found in the inputted phrase
    
    char* normalized = new char[letterCount+1];

    int normalizedIndex = 0;

    for (int i=0; i<phrase.size(); i++) {
        if (isalpha(phrase[i])) { // if a letter is found, adds it to normalized[] array and moves to the next index
                normalized[normalizedIndex] = tolower(phrase[i]); // makes each letter lowercase
                normalizedIndex++;
            }
    }

    normalized[normalizedIndex] = '\0'; // makes the final index of the normalized array the null character

    return normalized;
}

void countLetters(const char* phrase, int* frequencies) {
    for (int i=0; i<26; i++) { // initializes all 26 elements of the frequency array to 0
        frequencies[i] = 0;
    }
    for (int i=0; i< strlen(phrase); i++) { // loops through each character of the previously normalized phrase
        int letterIndex = *(phrase+i) - 'a'; // converts each letter in phrase into its appropriate index
        frequencies[letterIndex]++; // increments the index of the found letter by 1, ultimately counting how many of each letter are in the phrase
    }
}

bool areAnagrams(const int* firstCounts, const int* secondCounts) { // returns true if both phrases have the same amount of each individual letter. returns false if there is any discrepancy.
    for (int i=0; i<26; i++) {
        if (firstCounts[i] != secondCounts[i]) {
            return false;
        }
    }
    return true; // returns true if every instance of the loop isn't false
}
