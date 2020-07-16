#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
	public:
		Item(string name, string description);
		string GetName();
		string GetDescription();
		void EditDescription(string newDesc);
		void EditName(string newName);
		void ChangeStatus();
		bool LoanStatus();
		void Print() const;
		string ToString() const;
	private:
		string name;
		string description;
		bool isLoaned = false; //not useful rn but maybe for future stuff???
};

#endif