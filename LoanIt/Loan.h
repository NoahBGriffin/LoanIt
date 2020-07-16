#ifndef LOAN_H
#define LOAN_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "Item.h"

class Loan
{
	public:
		Loan(Item setLoanItem, string setPersonName, string setDate = "0");
		Item GetLoanItem();
		string GetLoanName();
		int GetLoanID();
		string GetDate();
		void SetDate(string setDate);
		void Print() const;
	private:
		Item loanItem = Item("None", "None");
		string personName = "None";
		int loanID = 0;
		string date = "00-00-00";
		static int nextID;
};

#endif
