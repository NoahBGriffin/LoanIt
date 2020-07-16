#include <string>
using namespace std;

#include "HelperFs.h"

// trims the white spaces from the start of a string
// @param s the string being trimmed
void ltrim(string& s) 
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
        }));
}

// trims the white spaces from the end of a string
// @param s the string being trimmed
void rtrim(string& s) 
{
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), s.end());
}

// trims the white spaces from the start and end of a string
// @param s the string being trimmed
void trim(string& s) 
{
    ltrim(s);
    rtrim(s);
}

/**
* Method checks to make sure inputs are not blank,
* if inputs are blank, prints an error message and repromts the user
* @param input the user input to be checked
* @param text the string for printing error messages specific to the desired input
* ie. "item name" if the input is about item name
*/
void InvalidInputHandler(string& input, string text)
{
    trim(input);
    while (input == "") //handle invalid input
    {
        cout << "\nError: Invalid " << text << ".\n";
        cout << "Please enter " << text << ": ";
        getline(cin, input);
        trim(input);
    }
}


/**
* Prompts the user to press enter and then returns
* @param ignoreCount the number of cin.ignore()s needed to return from the method to main
*/
void Return(int ignoreCount)
{
    cout << "\nPress enter to return to main menu.\n\n";
    for (int i = 0; i < ignoreCount; ++i)
    {
        cin.ignore();
    }
}