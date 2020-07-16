#ifndef EDIT_H
#define EDIT_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "Item.h"
#include "HelperFs.h"
#include "Print.h"

//functions for editing an item
// - consider implementing edit a loan ???
void EditItem(vector<Item>& itemList);
string ChangeItemName(Item& editItem);
void ChangeItemDescription(Item& editItem);

#endif // !EDIT_H
