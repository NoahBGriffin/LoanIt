#ifndef SAVELOAD_H
#define SAVELOAD_H

//all functions for saving + loading in LoanIt data + their helpers
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "Item.h"
#include "Loan.h"
#include "HelperFs.h"

void Save(vector<Item> itemList, vector<Loan> loanList);
void Load(vector <Item>& itemList, vector<Loan>& loanList, string saveFile);

#endif