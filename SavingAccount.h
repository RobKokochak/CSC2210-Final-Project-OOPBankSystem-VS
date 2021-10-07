#pragma once
#include "Account.h"
#include "CheckingAccount.h"

class SavingAccount : public Account {
private:
	float savingRate;
public:
	void setSavingRate(float rate);
	float getSavingRate() const;
	void deposit(float amount);
	float getBalance() const;
	void transfer(CheckingAccount& checkingAcc, float amount);
	SavingAccount(float amount, float rate);
};