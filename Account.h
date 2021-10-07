#pragma once

class Account {
protected:
	float balance;
public:
	virtual float getBalance() const = 0;
	virtual void deposit(float amount) = 0;
};

class greaterThanBal {}; // exception class for withdraw and transfer functions