#include "bankAccount_H.h"

bankAccount::bankAccount(int accountID,string accountName,double accountBalance)
	{
		id = accountID;
		name = accountName;
		if (accountBalance <= 0)
			balance = 0;
		else
			balance = accountBalance;
	}

int bankAccount::getID() const
{
	return id;
}

string bankAccount::getName() const
{
	return name;
}

double bankAccount::getBalance() const
{
	return balance;
}

void bankAccount::withdraw(double amount)
{
	if (amount <= balance)
		balance -= amount;
	else
		cout << "Insufficient Funds";
}

void bankAccount::deposit(double amount)
{
	if (amount > 0)
		balance += amount;
	else
		cout << "Incorrect Deposit Amount";
}

void bankAccount::print() const
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Account name:  " << name << endl;
	cout << "Account ID:  " << id << endl;
	cout << "Account balance:  $" << balance << endl;
}