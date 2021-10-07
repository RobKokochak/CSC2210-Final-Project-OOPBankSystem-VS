#include "BankSystem.h"

void BankSystem::AddCheckingDialog() {
	if (oneClient.checking != nullptr)
	{
		cout << "The client already has a checking account\n";
		log.push_back("Invalid attempt to overwrite a checking account.");
	}
	else
	{
		float balance;
		cout << "Enter the intial balance: ";
		cin >> balance;
		if (balance >= 0)
		{
			oneClient.checking = new CheckingAccount(balance);
			log.push_back("Checking account succesfully created.");
		}
		else
		{
			cout << "The balance cannot be less than 0. No action taken.";
			log.push_back("Invalid attempt to initialize a checking account - negative initial balance.");
		} 
	}
}
void BankSystem::RemoveCheckingDialog() {
	if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account\n";
		log.push_back("Invalid attempt to remove a non-existing checking account.");
	}
	else
	{
		delete oneClient.checking;
		oneClient.checking = nullptr;
		cout << "Checking account removed\n";
		log.push_back("Checking account succesfully removed.");
	}
}
void BankSystem::DepositCheckingDialog() {
	if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account\n";
		log.push_back("Invalid attempt to deposit in a non-existing checking account.");
	}
	else
	{
		float amount;
		cout << "Enter amount to deposit: ";
		cin >> amount;
		oneClient.checking->deposit(amount);
		string strAmount = to_string(amount);
		log.push_back("$" + strAmount + " successfully deposited in checking account.");
	}
}
void BankSystem::WithdrawCheckingDialog() {
	if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account\n";
		log.push_back("Invalid attempt to withdraw from a non-existing checking account.");
	}
	else
	{
		float amount;
		cout << "Enter amount to withdraw: ";
		cin >> amount;
		oneClient.checking->withdraw(amount);
		if (oneClient.checking->getBalance() - amount >= 0)
		{
			string strAmount = to_string(amount);
			log.push_back("$" + strAmount + " successfully withdrawn from a checking account.");
		}
		else
			log.push_back("Invalid attempt to withdraw from checking account: negative final balance.");
	}
}
void BankSystem::AddSavingDialog() {
	if (oneClient.saving != nullptr)
	{
		cout << "The client already has a savings account\n";
		log.push_back("Invalid attempt to overwrite a saving account.");
	}
	else
	{
		float balance, rate;
		cout << "Enter the account's initial balance: ";
		cin >> balance;
		cout << "Enter the account's saving rate: ";
		cin >> rate;
		oneClient.saving = new SavingAccount(balance,rate);
		log.push_back("Saving account succesfully created.");
	}
}
void BankSystem::RemoveSavingDialog() {
	if (oneClient.saving == nullptr)
	{
		cout << "The client does not have a saving account\n";
		log.push_back("Invalid attempt to remove a non-existing saving account.");
	}
	else
	{
		delete oneClient.saving;
		oneClient.saving = nullptr;
		cout << "Saving account removed\n";
		log.push_back("Saving account succesfully removed.");
	}
}
void BankSystem::DepositSavingDialog() {
	if (oneClient.saving == nullptr)
	{
		cout << "The client does not have a saving account\n";
		log.push_back("Invalid attempt to deposit in a non-existing saving account.");
	}
	else
	{
		float amount;
		cout << "Enter amount to deposit: ";
		cin >> amount;
		oneClient.saving->deposit(amount);
		string strAmount = to_string(amount);
		log.push_back("$" + strAmount + " successfully deposited in saving account.");
	}
}
void BankSystem::TransferDialog() {
	if (oneClient.saving == nullptr)
	{
		cout << "The client does not have a saving account\n";
		log.push_back("Invalid attempt to use a non-existing saving account.");
	}
	else if (oneClient.checking == nullptr)
	{
		cout << "The client does not have a checking account\n";
		log.push_back("Invalid attempt to use a non-existing checking account.");
	}
	else
	{
		float amount;
		cout << "Enter amount to transfer: ";
		cin >> amount;
		oneClient.saving->transfer(*oneClient.checking, amount);
		string strAmount = to_string(amount);
		log.push_back("$" + strAmount + " successfully transferred from saving to checking account.");

	}

}

void BankSystem::start() {
	int choice;
	cout << "= Menu =\n";
	cout << "1. Add a Checking Account\n";
	cout << "2. Remove Checking Account\n";
	cout << "3. Deposit into Checking Account\n";
	cout << "4. Withdraw from Checking Account\n";
	cout << "5. Add a Saving Account\n";
	cout << "6. Remove Saving Account\n";
	cout << "7. Deposit into Saving Account\n";
	cout << "8. Transfer from Saving to Checking Account\n";
	cout << "9. Exit\n";
	cout << "Choose an option [1-9]: ";
	cin >> choice;
	cout << endl;
	while (choice != 9) 
	{
		switch (choice)
		{
		case 1:
			AddCheckingDialog();
			break;
		case 2:
			RemoveCheckingDialog();
			break;
		case 3:
			DepositCheckingDialog();
			break;
		case 4:
			WithdrawCheckingDialog();
			break;
		case 5:
			AddSavingDialog();
			break;
		case 6:
			RemoveSavingDialog();
			break;
		case 7:
			DepositSavingDialog();
			break;
		case 8:
			TransferDialog();
			break;
		}
		cout << "\n= Menu =\n";
		cout << "1. Add a Checking Account\n";
		cout << "2. Remove Checking Account\n";
		cout << "3. Deposit into Checking Account\n";
		cout << "4. Withdraw from Checking Account\n";
		cout << "5. Add a Saving Account\n";
		cout << "6. Remove Saving Account\n";
		cout << "7. Deposit into Saving Account\n";
		cout << "8. Transfer from Saving to Checking Account\n";
		cout << "9. Exit\n";
		cout << "Choose an option [1-9]: ";
		cin >> choice;
		cout << endl;
	}
	cout << "Exit\n";
	cout << "\nLog of events:\n";
	for (int i = 0; i < log.size(); i++)
		cout << i+1 << ": " << log[i] << endl;
}
BankSystem::BankSystem(int i, string fn, string ln) {
	oneClient = Client(i,fn,ln);
}