#pragma once
#include "SavingAccount.h"
#include <string>
using namespace std;

class Client {
private:
	int id;
	string firstName;
	string lastName;
public:
	CheckingAccount* checking;
	SavingAccount* saving;
	void setID(int i);
	int getID() const;
	void setName(string fn, string ln);
	string getFirstName() const;
	string getLastName() const;
	Client(int i, string fn, string ln);
	Client();
};