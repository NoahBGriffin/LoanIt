#include "Print.h"

/**
* Prints the list of items currently in the LoanIt tracker
* @param itemList the list of items in LoanIt to be printed
* @param mainMenu if true it will go to Return which creates a prompt to return to the main menu
*/
void PrintItemList(vector<Item> itemList, bool mainMenu)
{
    cout << "Printing list of items....\n\n";
    for (auto i : itemList)
    {
        i.Print();
    }
    cout << endl;
    if (mainMenu)
    {
        Return(2);
    }
}


/**
* Prints the list of loans in the LoanIt tracker
* @param loanList the list of laons in LoanIt to be printed
*/
void PrintLoanList(vector<Loan> loanList, bool mainMenu)
{
    cout << "Printing list of loans....\n\n";
    for (auto i : loanList)
    {
        i.Print();
    }
    cout << endl;
    if (mainMenu)
    {
        Return(2);
    }
}