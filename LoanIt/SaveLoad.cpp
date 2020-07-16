#include "SaveLoad.h"

/**
* Saves the LoanIt information to an external text file named "LoanItSaveData.txt"
* @param itemList the list of all the items in LoanIt
* @param loanList the list of all the loans in LoanIt
*/
void Save(vector<Item> itemList, vector<Loan> loanList)
{
    string loaned;
    Item loanItem = Item("", "");
    ofstream loanItFile("LoanItSaveData.txt");

    if (loanItFile.is_open())
    {
        loanItFile << "ITEMS:\n";
        for (auto i : itemList)
        {
            loanItFile << i.GetName() << ": " << i.GetDescription() << "\n";
        }
        loanItFile << "\nLOANS:";
        for (auto i : loanList)
        {
            loanItem = i.GetLoanItem();
            loanItFile << "\n" << i.GetLoanID() << ") " << loanItem.ToString() << " - " <<
                i.GetLoanName() << ", " << i.GetDate();
        }
        loanItFile.close();
        cout << "LoanIt data successfully saved to \"LoanItSaveData.txt\"\n";
    }
    else cout << "Unable to save\n";

    Return(2);
}

/**
* Loads items and loans to LoanIt from an external text document named "LoanItSaveData.txt"
* @param itemList the item list which will have item data from the document loaded on to it
* @param loanList the loan list which will have loan data from the document loaded on to it
* @param saveFile the name of the file being loaded in
*/
void Load(vector <Item>& itemList, vector<Loan>& loanList, string saveFile)
{
    ifstream readfile;
    bool item = true;
    //item variables
    string tmpItemName;
    string tmpItemDesc;
    //loan variables
    int tmpLoanID;
    string tmpLoanPName;
    string tmpLoanDate;
    Item tmpLoanItem = Item("", "");

    readfile.open(saveFile);
    if (!readfile)
    {
        cout << "No previous save data found.\n";
    }
    else
    {
        getline(readfile, tmpItemName, '\n');
        if (tmpItemName == "ITEMS:") {
            while (!readfile.eof())
            {
                while (item) //get all the items
                {
                    getline(readfile, tmpItemName, ':'); //read item name
                    if (tmpItemName == "\nLOANS") //check for break to loans
                    {
                        item = false;
                        break;
                    }
                    getline(readfile, tmpItemDesc, '\n');
                    trim(tmpItemName); //trim whitespace from name
                    trim(tmpItemDesc); //trim whitespace from desc
                    itemList.push_back(Item(tmpItemName, tmpItemDesc)); //put in list
                }
                //now find all the loans
                if (!item && !readfile.eof())
                {
                    readfile >> tmpLoanID;
                    readfile.ignore(); //ignore the : char
                    getline(readfile, tmpItemName, ':');
                    getline(readfile, tmpItemDesc, '-');
                    getline(readfile, tmpLoanPName, ',');
                    readfile >> tmpLoanDate;
                    trim(tmpItemName); //trim whitespace from item name
                    trim(tmpItemDesc); //trim whitespace from item description
                    trim(tmpLoanPName); //trim whitespace from person's name
                    tmpLoanItem = Item(tmpItemName, tmpItemDesc); //FIX THIS
                    tmpLoanItem.ChangeStatus();
                    loanList.push_back(Loan(tmpLoanItem, tmpLoanPName, tmpLoanDate)); //put loan in the list
                }
            }
            cout << "Load complete.\n";
        }
        else cout << "Error: Unable to read in LoanIt data.\n";

        readfile.close();
    }
}