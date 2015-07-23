//***************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the class linkedQueueType 
// in a program.
//***************************************************************
 
#include <iostream>
#include <string>
#include "linkedQueue.h"
#include "myStack.h"

using namespace std;

template <class Type>
void reverseQueue (linkedQueueType<Type> &givenQueue)
{
	stackType<Type> reverseStack;

	while (!givenQueue.isEmptyQueue())
	{
		reverseStack.push(givenQueue.front());
		givenQueue.deleteQueue();
	}

	givenQueue.initializeQueue();

	while (!reverseStack.isEmptyStack())
	{
		givenQueue.addQueue(reverseStack.top());
		reverseStack.pop();
	}
}

int main()
{
    linkedQueueType<int> queue;
    
    queue.initializeQueue();
    
	int num;                                    

	cout << "Testing Reverse Queue" << endl;
	cout << "Add numbers to the Queue" << endl;
	cout << "Enter numbers, end with -999:" << endl;

	cin >> num;

	while (num != -999)                         
    {
		queue.addQueue(num);
		cin >> num;
	}

	cout << endl << "Reversing Queue..." << endl;

	reverseQueue(queue);

    cout << endl << "Queue Elements: ";

    while (!queue.isEmptyQueue())
    {
        cout << queue.front() << " ";
        queue.deleteQueue();
    }

    cout << endl;
	cin.ignore(256, '\n');  //used to ignore the return entered for reverseQueue Input

	//Testing for Palindromes Start
	
	string line;
	linkedQueueType<char> textQueue;
	stackType<char> textStack;
	bool palindrome;

	cout << endl << "Testing for Palindromes" << endl;
	cout << "Enter a string to check for Palindromes:" << endl;
	getline(cin, line);
	for (int i = 0; i < line.size(); i++)
	{
		char letter;
		if (!ispunct(line[i]))
		{
			letter = line[i];
			textQueue.addQueue(tolower(letter));
			textStack.push(tolower(letter));
		}
	}

	palindrome = true;

	while (!textQueue.isEmptyQueue())
	{
		if (textQueue.front() == textStack.top())
		{
			textQueue.deleteQueue();
			textStack.pop();
		}
		else
		{
			palindrome = false;
			break;
		}
	}

	if (palindrome == true)
		cout << endl << "The String is a palindrome." << endl;
	else
		cout << endl << "The String is not a palindrome." << endl;

	/*
	cout << endl << "From textQueue:" << endl;

	while (!textQueue.isEmptyQueue())
    {
        cout << textQueue.front() << " ";
        textQueue.deleteQueue();
    }

	cout << endl << "From textStack:" << endl;
	
	while (!textStack.isEmptyStack())
	{
		cout << textStack.top() << " ";
		textStack.pop();
	}
	*/

	cout << endl;

    return 0;

	/*For palindrome
	string line
	getline(line, ____);
	for (i = 0, i < line.size(), i++)
	if (!ispunct(line[i])) //also check for spaces, this only checks punctuations
	{
		myq.insert(tolower(line[i]));
		myStack.push(tolower(line[i]));
	}
	*/


}
