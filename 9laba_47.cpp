#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція обробки рядка
string processString(const string& input) {
    string result;
    bool previousWasSpace = false;
    
    for (char c : input) {
        if (isspace(c)) {
            if (!previousWasSpace) {
                result += '.';
                previousWasSpace = true;
            }
        } else {
            result += c;
            previousWasSpace = false;
        }
    }
    
    return result;
}

// Функція перевірки рядка
bool satisfiesConditions(const string& input) {
    for (char c : input) {
        if (!isspace(c) && !isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    ifstream inputFile("input_47.txt");
    ofstream outputFile("output_47.txt");

    if (!inputFile.is_open()) {
        cerr << "Unable to open input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Unable to open output file!" << endl;
        return 1;
    }
    
    
    
    while (getline(inputFile, input)) {
        if (satisfiesConditions(input)) {
            string processed = processString(input);
            outputFile << processed << endl;
            cout << "Read line from file: " << input << endl << endl;
            cout << "Modified string: " << processed << endl << endl;
            cout << "Check file 'output_47.txt'" << endl;
        } else {
            cerr << "Input string does not satisfy conditions: " << input << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
