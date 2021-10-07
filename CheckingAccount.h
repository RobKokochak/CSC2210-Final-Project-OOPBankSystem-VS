#pragma once

#include "Account.h"

class CheckingAccount : public Account {
public:
	void withdraw(float amount);
	void deposit(float amount);
	float getBalance() const;
	CheckingAccount(float amount);
};
