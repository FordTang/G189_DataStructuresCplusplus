#ifndef bankAccount_H
#define bankAccount_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class bankAccount
{
private:
	int id;
	string name;
	double balance;

public:
	bankAccount(int accountID,string accountName,double accountBalance);

	int getID() const;

	string getName() const;

	double getBalance() const;

	void withdraw(double amount);

	void deposit(double amount);

	void print() const;
};

#endif