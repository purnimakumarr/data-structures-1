/*
Write a program to implement AVL Trees. Perform following operations:
(i) Insertion
(ii) Deletion
*/

#include<iostream>

using namespace std;

//structure of node
struct node
{
	node *left, *right, *parent;
	int data, bf, height;
}*root=NULL;

class AVLTree
{
	node * p, * q;
public:
	AVLTree();
	void insertion();
	void deletion();
};
int main()
{
	AVLTree obj; char ch;
	do
	{
		cout << "MENU DRIVEN PROGRAM TO PERFORM CERTAIN FUNCTIONS ON AVL TREES";
		cout << "\n1. Insertion";
		cout << "\n2.Deletion";
		cout << "Enter choice : ";
		cin >> ch;

		switch (ch)
		{
		case '1': obj.insertion();
			break;
		case '2': obj.deletion();
			break;
		default: cout << "\nINVALID INPUT";
		}
	}
	return 0;
}