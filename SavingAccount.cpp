#include "SavingAccount.h"
#include <iostream>
using namespace std;

void SavingAccount::setSavingRate(float rate) {
	savingRate = rate;
}
float SavingAccount::getSavingRate() const {
	return savingRate;
}
void SavingAccount::deposit(float amount) {
	if (balance += amount >= 0)
		balance += amount;
}
float SavingAccount::getBalance() const {
	return balance;
}
void SavingAccount::transfer(CheckingAccount& checkingAcc, float amount) {
	try
	{
		if (amount > balance)
			throw greaterThanBal();
		balance -= amount;
		checkingAcc.deposit(amount);
	}
	catch (greaterThanBal)
	{
		cout << "It cannot withdraw an amount greater than the balance. No changes were done to the balance.\n";
	}
}
SavingAccount::SavingAccount(float amount, float rate) {
	balance = amount;
	savingRate = rate;
}