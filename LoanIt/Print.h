#ifndef PRINT_H
#define PRINT_H

#include <vector>
#include <string>

#include "Item.h"
#include "Loan.h"
#include "HelperFs.h"

void PrintItemList(vector<Item> itemList, bool mainMenu);
void PrintLoanList(vector<Loan> loanList, bool mainMenu);

#endif // !PRINT_H
