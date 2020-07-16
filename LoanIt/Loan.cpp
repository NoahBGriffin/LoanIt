#include "Loan.h"

//Constructor for loan
Loan::Loan(Item setLoanItem, string setPersonName, string setDate)
{
	this->loanItem = setLoanItem;
	setLoanItem.ChangeStatus();
	this->personName = setPersonName;
	this->date = setDate;
	loanID = nextID;
	
	++nextID;

	if (setDate == "0") //set date if none is passed in
	{
		//get date
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, sizeof(buffer), "%m-%d-%Y", timeinfo);
		string str(buffer);
		date = str;
	}
}

//Accessor for Loan item object
Item Loan::GetLoanItem()
{
	return loanItem;
}

//Accessor for the name of the person the loan went out to
string Loan::GetLoanName()
{
	return personName;
}

//Accessor for unique loan ID
int Loan::GetLoanID()
{
	return loanID;
}

//Accessor for date the loan was made
string Loan::GetDate()
{
	return date;
}

//Mutator for date the loan was made
void Loan::SetDate(string setDate)
{
	this->date = setDate;
}

//Prints the loan information
void Loan::Print() const
{
	cout << "Loan " << loanID << ") " << loanItem.ToString()
		 << " - to " << personName << " on " << date << ".\n";
}

int Loan::nextID = 101; //the first loanID, increments upwards from this value