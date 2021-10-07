#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Client.h"

class BankSystem {
private:
	vector<string> log;
	Client oneClient;
	void AddCheckingDialog();
	void RemoveCheckingDialog();
	void DepositCheckingDialog();
	void WithdrawCheckingDialog();
	void AddSavingDialog();
	void RemoveSavingDialog();
	void DepositSavingDialog();
	void TransferDialog();
public:
	void start();
	BankSystem(int i, string fn, string ln);
};