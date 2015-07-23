//**********************************************************
// Author: D.S. Malik / Ford Tang (edited)
//
// This program tests the various operations on an ordered
// linked list.  Edited to test new functions.
//**********************************************************
 
#include <iostream>
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"

using namespace std;                            

int main()                                      
{
	unorderedLinkedList<int> myList, otherList;
    orderedLinkedList<int> list1, list2, newList;
	
    int num;                                    

	cout << "Testing unorderedLinkedList" << endl;
	cout << "Enter numbers, end with -999:" << endl;

	cin >> num;

	while (num != -999)                         
    {
		myList.insertLast(num);
		cin >> num;
	}
	
	cout << endl;

	cout << "unorderedLinkedList:  ";
	myList.print();
	cout << endl << "Choose a number to divide the list:  ";
	cin >> num;
	myList.divideAt(otherList, num);

	cout << endl << "Original List (count of " << myList.length() <<"):  ";
	myList.print();
	cout << endl << "Divided List (count of " << otherList.length() <<"):  ";
	otherList.print();
	
	cout << endl;

	cout << endl << "Testing orderedLinkedList" << endl;
    cout << "First List" << endl << "Enter numbers, end with -999:" << endl;               
    cin >> num;                                 

    while (num != -999)                         
    {                                           
        list1.insert(num);                      
        cin >> num;                             
    }                                           

    cout << endl;                               

    cout << "list1: ";                 
    list1.print();                              
    cout << endl;                               

    cout << endl << "Second List" << endl << "Enter numbers, end with -999:" << endl;               
    cin >> num;                                 

    while (num != -999)                         
    {                                           
        list2.insert(num);                      
        cin >> num;                             
    }                                           

    cout << endl; 

    cout << "list2: ";                 
    list2.print();                              
    cout << endl;                               

    cout << endl << "Merging Lists" << endl;
	newList.mergeLists(list1,list2);
	cout << "Merged List Data:" << endl;
	newList.print();

	cout << endl << endl << "First List is now:  ";
	list1.print();

	cout << endl << "Second List is now:  ";
	list2.print();

	cout << endl;
	
	cout << endl << "Search merged list:  ";
	cin >> num;
	if (newList.search(num))
		cout << num << " is in the list" << endl;
	else
		cout << num << " is not on the list." << endl;

    return 0;					                
}