// LoanIt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LoanIt.h"


int main(int argc, char* argv[])
{
    int menuSelect = 9;
    bool exit = false;
    vector<Item> itemList;
    vector<Loan> loanList;
    string filename = "LoanItSaveData.txt";


    entryMessage();

    if (argc > 2) //this gets command line arguments to read in file, if there are any
    {
        if (strcmp(argv[1], "-f") == 0) //checks for the -f prompt
        {
            filename = argv[2];
        }
    }
    Load(itemList, loanList, filename);

    //MENU PIECES
    while (!exit)
    {
        cout << "\n\tMENU\n";
        cout << "-----------------------\n";
        cout << "Enter the corresponding number to select a menu item\n\n";
        cout << "1. " << "Create Item\n";
        cout << "2. " << "Create Loan\n";
        cout << "3. " << "Edit an item's details\n";
        cout << "4. " << "List all items\n";
        cout << "5. " << "List all loans\n";
        cout << "6. " << "Delete an item\n";
        cout << "7. " << "Delete a loan\n";
        cout << "8. " << "Save\n";
        cout << "9. " << "Exit program\n\n";

        //get a numeric value from the user for menu selection
        while (true)
        {
            cin >> menuSelect;
            if (!cin)
            {
                cout << "Menu selection must be a numeric value.\n";
                cout << "Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        cout << endl;
        switch (menuSelect) //handle menu options
        {
        case 1:
            CreateItem(itemList);
            continue;
        case 2:
            CreateLoan(loanList, itemList);
            continue;
        case 3:
            if (itemList.empty()) cout << "The item list is empty.\n\n";
            else EditItem(itemList);
            continue;
        case 4:
            if (itemList.empty()) cout << "The item list is empty.\n\n";
            else PrintItemList(itemList, true);
            continue;
        case 5:
            if (loanList.empty()) cout << "The loan list is empty.\n\n";
            else PrintLoanList(loanList, true);
            continue;
        case 6:
            if (itemList.empty()) cout << "Item list is empty, nothing to delete.\n\n";
            else DeleteItem(itemList);
            continue;
        case 7:
            if (loanList.empty()) cout << "Loan list is empty, nothing to delete.\n\n";
            else DeleteLoan(loanList, itemList);
            continue;
        case 8:
            Save(itemList, loanList);
            continue;
        case 9:
            cout << "Thank you for Using LoanIt.\n";
            exit = true;
            break;
        default:
            cout << "Error: Menu selection unknown\n";
            cout << "Please make another selection\n";
            continue;
        }
        
    }

    return 0;
}

/**
*Prints the entry message for the user
*/
void entryMessage()
{
    cout << "\n WELCOME TO LOANIT\n";
    cout << "This program keeps track of your items and who you"
        << " have loaned them out to!\n\n";
    cout << "Items you have not loaned will be tracked in an item list with their name and description.\n";
    cout << "When an item is loaned it will be moved to a loan list, you will be prompted to enter the name of the person ";
    cout << "you loaned the item to.\n";
    cout << "LoanIt will track the date the loan was created and assign it a unique Loan ID number.\n";
    cout << "Any previous save files will now be loaded in...\n";
}

