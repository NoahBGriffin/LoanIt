#ifndef CREATEDELETE_H
#define CREATEDELETE_H

#include <vector>
#include <string>

using namespace std;

#include "Item.h"
#include "Loan.h"
#include "HelperFs.h"
#include "Print.h"

//All functions for creating + deleting items and loans from their respective lists
void CreateItem(vector<Item>& itemList);
void CreateLoan(vector<Loan>& loanList, vector<Item>& itemList);
void DeleteItem(vector<Item>& itemList);
bool FindAndDelete(vector<Item>& itemList, string deleteThis);
void DeleteLoan(vector<Loan>& loanList, vector<Item>& itemLIst);

#endif
