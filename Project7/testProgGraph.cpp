
#include <iostream>
#include <fstream>
#include "binarySearchTree.h"
#include "weightedGraph.h"

using namespace std;

int main()
{ 
    cout << "Project 7:  #11 page 683 Start" << endl << endl;
	
	int num;
	ofstream ofFile;

	cout << "Add Numbers into the Binary Search Tree File (BST.txt)" << endl;
	cout << "Enter numbers, end with -999:" << endl;

	ofFile.open ("BST.txt");
	cin >> num;
	while (num != -999)                         
    {
		ofFile << num << endl;
		cin >> num;
	}
	ofFile.close();

	cout << endl << endl << "Creating Binary Search Tree t1" << endl;
	bSearchTreeType<int> t1;

	ifstream ifFile ("BST.txt");
	ifFile >> num;
	while (!ifFile.eof())
    {
		t1.insert(num);
		ifFile >> num;
    }
    ifFile.close();

	cout << endl << "Creating Binary Search Tree t2 with postorder traversal of t1" << endl;
	t1.postorderTraversal();
	
	bSearchTreeType<int> t2;
	ifFile.open("BST.txt");
	ifFile >> num;
	while (!ifFile.eof())
    {
		t2.insert(num);
		ifFile >> num;
    }
    ifFile.close();

	cout << endl << "Creating Binary Search Tree t3 with preorder traversal of t2" << endl;
	t2.preorderTraversal();

	bSearchTreeType<int> t3;
	ifFile.open("BST.txt");
	ifFile >> num;
	while (!ifFile.eof())
    {
		t3.insert(num);
		ifFile >> num;
    }
    ifFile.close();

	cout << endl << "Using inorder traversal on t3:" << endl;
	t3.inorderTraversal();
	cout << endl;

	cout << endl << "t1 Height:  " << t1.treeHeight() << "  |  t1 leafs:  " << t1.treeLeavesCount() << endl;
	cout << endl << "t2 Height:  " << t2.treeHeight() << "  |  t2 leafs:  " << t2.treeLeavesCount() << endl;
	cout << endl << "t3 Height:  " << t3.treeHeight() << "  |  t3 leafs:  " << t3.treeLeavesCount() << endl;

	cout << endl << "Project 7:  #11 page 683 End" << endl;

	cout << endl << "-----------------------------" << endl;

	cout << endl << "Press any key to continue..." << endl;

	cin.get();
	cin.get();

	cout << endl << "Project 7:  #3 page 727 Start" << endl << endl;

	weightedGraphType(5);



	return 0;
 }