#include "CheckingAccount.h"
#include <iostream>
using namespace std;

void CheckingAccount::withdraw(float amount) {
	try
	{
		if (amount > balance)
			throw greaterThanBal();
		balance -= amount;
	}
	catch (greaterThanBal)
	{
		cout << "It cannot withdraw an amount greater than the balance. No changes were done to the balance.\n";
	}
}

void CheckingAccount::deposit(float amount) {
	if (balance += amount >= 0)
		balance += amount;
}

float CheckingAccount::getBalance() const {
	return balance;
}
CheckingAccount::CheckingAccount(float amount) {
	if (amount >= 0)
		balance = amount;
	else
		cout << "Balance can not be less than 0.\n";
}