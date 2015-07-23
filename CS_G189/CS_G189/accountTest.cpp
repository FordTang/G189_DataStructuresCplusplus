#include "bankAccount_H.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int accountID;
	string accountName;
	double accountBalance;

	cout << "Enter Account ID:  ";
	cin >> accountID;

	cout << "Enter Account Name:  ";
	cin >> accountName;

	cout << "Enter Account Balance (positive):  ";
	cin >> accountBalance;

	bankAccount myAccount(accountID, accountName, accountBalance);

	myAccount.withdraw(1000);

	myAccount.deposit(100);

	myAccount.print();

	return 0;
}