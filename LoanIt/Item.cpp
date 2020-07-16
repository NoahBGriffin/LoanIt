#include "Item.h"

//Constructor for Item
//@param setName the name of the item
//@param setDescription a brief description of the item
Item::Item(string setName = "", string setDescription = "")
{
	this->name = setName;
	this->description = setDescription;
}

//accessor for the name of the item
string Item::GetName()
{
	return name;
}

//accessor for the item's description
string Item::GetDescription() 
{
	return description;
}

//mutator for the item's description
void Item::EditDescription(string newDesc)
{
	this->description = newDesc;
}

//mutator for the item's name
void Item::EditName(string newName)
{
	this->name = newName;
}

//changes the status of the item (loaned vs. not loaned)
//just swaps between the two values when called
void Item::ChangeStatus()
{
	if(isLoaned) 
	{
		isLoaned = false;
	}
	else
	{
		isLoaned = true;
	}
}

//returns true if item is on loan, false if it is not
bool Item::LoanStatus()
{
	return isLoaned;
}

//prints item information
void Item::Print() const
{
	cout << name << ": " << description << endl;
}

//returns string representation of the item
string Item::ToString() const
{
	string tostring = name + ": " + description;
	return tostring;
}