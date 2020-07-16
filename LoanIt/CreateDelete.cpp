#include "CreateDelete.h"


/**
* Prompts user for an item name and short description, then creates an
* item from that and adds it to LoanIt's list of items
*
* @param itemList the list of item's the brand new item is being added to
*/
void CreateItem(vector<Item>& itemList)
{
    string itemName;
    string itemDescription;
    cout << "Enter item name followed by a brief description of that item\n";
    cout << "Please note all leading and trailing spaces will be removed.\n\n";

    //GET ITEM NAME
    cout << "Item Name: ";
    cin.ignore();
    getline(cin, itemName);
    InvalidInputHandler(itemName, "item name");

    //GET ITEM DESCRIPTION
    cout << "Item Description: ";
    getline(cin, itemDescription);
    InvalidInputHandler(itemDescription, "item description");
    cout << endl;

    //add item to the list
    Item temp = Item(itemName, itemDescription);
    itemList.push_back(temp);

    cout << "Item has been successfully added.\n";

    Return(1);
}

/**
* Prompts the user for an item, checks that the item is in the item list, and prompts the user for
* a name of the person the item is being loaned out to. Then adds this loan to the loan list.
*
*/
void CreateLoan(vector<Loan>& loanList, vector<Item>& itemList)
{
    string loanItem;
    string personName;
    bool itemMatch = false;
    auto iter = itemList.begin();

    cout << "Enter the item that is being loaned out, followed by the name of the person "
        << "it is being loaned to.\n";

    //GET LOAN ITEM
    cout << "Loan item: ";
    cin.ignore();
    getline(cin, loanItem);
    InvalidInputHandler(loanItem, "loan item");
    //handle loan item not matching an item in item list
    while (!itemMatch)
    {
        for (auto i : itemList)
        {
            if (i.GetName() == loanItem)
            {
                itemMatch = true;
                i.ChangeStatus();
                //GET NAME
                cout << "Name of person item is loaned to: ";
                getline(cin, personName);
                InvalidInputHandler(personName, "name of person");

                //add to list
                Loan temp = Loan(i, personName);
                loanList.push_back(temp);
                i.ChangeStatus();
                //delete from itemList
                FindAndDelete(itemList, i.GetName());
                cout << "Loan has been successfully added.\n";


            }
        }
        if (!itemMatch)
        {
            cout << "Error: Item not found in item list.\n";
            PrintItemList(itemList, false);
            cout << "Please enter loan item again: ";
            getline(cin, loanItem);
            InvalidInputHandler(loanItem, "loan item");
        }
    }


    Return(1);
}

/**
* Prompts the user for the name of an item in the LoanIt tracker, checks
* that the item is in the item list, and then deletes it
* @param itemList the list of items in LoanIt
*/
void DeleteItem(vector<Item>& itemList)
{
    string deleteThis;
    bool itemFound = false;
    auto iter = itemList.begin();

    //get name of item to be deleted
    cout << "Please enter the name of the item you would like to delete.\n";
    cout << "Item name: ";
    cin.ignore();
    getline(cin, deleteThis); //IGNORE CASE LATER
    InvalidInputHandler(deleteThis, "item name");

    //check if item is in itemList
    while (!itemFound)
    {
        itemFound = FindAndDelete(itemList, deleteThis);
        //if item is not found, print list of items and reprompt the user for a new item
        if (!itemFound)
        {
            cout << "\nError: Item not found.\n";
            PrintItemList(itemList, false);
            cout << "\nPlease enter another item.\n";
            cout << "Item name: ";
            getline(cin, deleteThis);
            InvalidInputHandler(deleteThis, "item name");
        }
        else //if it is found, let user know it has been deleted
        {
            cout << deleteThis << " has been successfully deleted.\n";

        }
        iter = itemList.begin();
    }

    Return(1);
}

bool FindAndDelete(vector<Item>& itemList, string deleteThis)
{
    bool itemFound = false;
    auto iter = itemList.begin();

    //find and delete item
    while (iter != itemList.end())
    {
        //delete item when found
        if (iter->GetName() == deleteThis)
        {
            itemFound = true;
            iter = itemList.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return itemFound;
}

/**
* Prompts the user for a loanID and checks if that ID matches a loan in the
* LoanIt tracker, then deletes it
* @param loanList the list of loans in the LoanIt tracker
*/
void DeleteLoan(vector<Loan>& loanList, vector<Item>& itemList)
{
    int deleteThis;
    bool loanFound = false;
    auto iter = loanList.begin();
    Item saveItem = Item("", "");

    //get ID of loan to be deleted
    cout << "Please enter the Loan ID of the loan you wish to delete.\n";
    cout << "Loan ID: ";
    cin.ignore();

    //find loan ID in loanList
    while (!loanFound)
    {

        //get a numeric value from the user
        while (true)
        {
            cin >> deleteThis;
            if (!cin)
            {
                cout << "Loan ID must be a numeric value.\n";
                cout << "Enter another Loan ID: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else break;
        }

        //find and delete item
        while (iter != loanList.end())
        {
            //delete item when found
            if (iter->GetLoanID() == deleteThis)
            {
                loanFound = true;
                saveItem = iter->GetLoanItem();
                iter = loanList.erase(iter);
                itemList.push_back(saveItem);
            }
            else
            {
                ++iter;
            }
        }

        //if item is not found, print the list of loans and reprompt the user for a new item
        if (!loanFound)
        {
            cout << "\nError: Loan not found.\n";
            PrintLoanList(loanList, false);
            cout << "\nPlease enter another loan ID.\n";
            cout << "Loan ID: ";
        }
        else //if it is found, let user know it has been deleted
        {
            cout << "Loan " << deleteThis << " has been successfully deleted.\n";
        }
        iter = loanList.begin();
    }

    Return(2);
}