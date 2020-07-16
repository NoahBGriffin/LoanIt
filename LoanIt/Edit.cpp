#include "Edit.h"

/**
* Prompts the user for an item from the item list, double-checks that item is in the list, and
* allows the user to change it's description to something new
* @param itemList the list of items the user has added to LoanIt
*/
void EditItem(vector<Item>& itemList)
{
    string itemName;
    string itemDescription;
    bool itemFound = false;
    vector<Item>::iterator iter;
    int editSelect;
    bool menu = true;

    cout << "You can change the description of a particular item that is not currently loaned.\n";
    cout << "Please enter the name of the item whose description you want to change.\n";
    cout << "Item name: ";
    cin.ignore();
    getline(cin, itemName);
    InvalidInputHandler(itemName, "item name");
    cout << endl;

    while (!itemFound)
    {
        //find item
        for (iter = itemList.begin(); iter != itemList.end(); ++iter)
        {

            if (iter->GetName() == itemName) //item found handle editing stuff
            {
                itemFound = true;
                while (menu)
                {
                    while (true) //print edit menu
                    {
                        cout << "Would you like to enter a new name, new description, or change both?\n";
                        cout << "1. Change name.\n";
                        cout << "2. Change description.\n";
                        cout << "3. Change both.\n";

                        cin >> editSelect;
                        if (!cin) //get edit choice from user
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
                    cin.ignore();
                    switch (editSelect)
                    {
                    case 1: //edit name
                        itemName = ChangeItemName(*iter);
                        menu = false;
                        break;
                    case 2: //edit description
                        ChangeItemDescription(*iter);
                        menu = false;
                        break;
                    case 3:
                        itemName = ChangeItemName(*iter);
                        ChangeItemDescription(*iter);
                        menu = false;
                        break;
                    default:
                        cout << "Menu selection unknown, please try again.\n";
                        continue;
                    }
                }
            }
        }

        //if item is not found, list all items and reprompt the user for a new item
        if (!itemFound)
        {
            cout << "\nError: Item not found.\n";
            PrintItemList(itemList, false);
            cout << "\nPlease enter another item.\n";
            cout << "Item name: ";
            getline(cin, itemName);
            InvalidInputHandler(itemName, "item name");
        }
        else //if it is found, let user know it has been deleted
        {
            cout << itemName << " has been successfully edited.\n";

        }
    }

    Return(1);
}

//changes the item name based on user prompt
string ChangeItemName(Item& editItem)
{
    string itemName;
    cout << "Please enter a new name for the item: \n";
    getline(cin, itemName);
    InvalidInputHandler(itemName, "item name");
    editItem.EditName(itemName);
    return itemName;
}

//changes the item description based on user prompt
void ChangeItemDescription(Item& editItem)
{
    string itemDesc;
    cout << "Please enter a new description for the item: \n";
    getline(cin, itemDesc);
    InvalidInputHandler(itemDesc, "item description");
    editItem.EditDescription(itemDesc);
}