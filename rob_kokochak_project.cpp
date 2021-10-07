// rob_kokochak_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "BankSystem.h"

int main()
{
	BankSystem bank(1, "Rob", "Kokochak");
	bank.start();
}