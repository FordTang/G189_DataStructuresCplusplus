//**********************************************************
// Author: Ford Tang
//
// This program tests the reverseStack function and converts
// binary to decimal using stacks.
//**********************************************************
 
#include <iostream>
#include "myStack.h"

using namespace std;                            

int main()
{
	stackType<int> stack1;
	stackType<int> stack2;
	stackType<int> binaryStack;
	int count, input, decimal;
	
	cout << "Testing reverseStack function" << endl;
	cout << "Enter numbers, end with -999:" << endl;

	cin >> input;

	while (input != -999)                         
    {
		stack1.push(input);
		cin >> input;
	}

	cout << endl << "Starting reverseStack function into second stack" << endl;

	stack1.reverseStack(stack2);

	cout << "Popping first stack (normal order):" << endl;

	while (!stack1.isEmptyStack())
	{
		cout << stack1.top() << " ";

		stack1.pop();
	}
	
	cout << endl << "Popping second stack (reverse order):" << endl;

	while (!stack2.isEmptyStack())
	{
		cout << stack2.top() << " ";

		stack2.pop();
	}

	cout << endl << endl;

	cout << "Converting binary to decimals." << endl;
	cout << "Please enter a binary number:"  << endl;
	cin >> input;

	count = 0;
	decimal = 0;
	
	while (input > 0)
	{
		binaryStack.push(input % 10);
		input = input / 10;
		count ++;
	}

	while (!binaryStack.isEmptyStack())
	{
		count--;
		decimal += binaryStack.top() * pow(2, count);
		binaryStack.pop();
	}

	cout << "Binary number converted to decimal form is:  " << decimal << endl;

	return 0;
}