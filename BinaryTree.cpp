//The menu drievn program implements different operations in a binary search tree.

#include <iostream>
#include<stdio.h>

using namespace std;

#define size 10

//structure of node
struct Node
{
    int data;
    Node* left;
    Node* right;
}*root=NULL;

class stack
{
    Node* arr[size];
    int top;
public:
    void push(Node*);
    Node* pop();
    int isempty();
    stack();
};

class BinarySearchTree
{
    Node *p, *q, *p1;

public:

    BinarySearchTree();
    void insert();
    void recursive_preorder(Node*);
    void recursive_postorder(Node*);
    void recursive_inorder(Node*);
    void count_leaf(Node*, int);
};

//construtor for stack
stack::stack()
{
    top = -1;
}

//checks if stack is empty
int stack ::isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

//push operation for stack
void stack ::push(Node* item)
{
    if (top == size - 1)
        cout << "Overflow.";
    else
        arr[++top] = item;
}

//pop operation for stack
Node* stack ::pop()
{
    Node* a;
    if (isempty())
        cout << "Underflow.";
    else
    {
        a = arr[top];
        top--;
    }
    return a;
}


//constructor for binary search tree
BinarySearchTree::BinarySearchTree()
{
    p = NULL;
    p1 = NULL;
    q = NULL;
}
//takes input from user and inserts the value in the tree
void BinarySearchTree::insert()
{
    int item;
    cout << "Enter data to be inserted, otherwise enter zero to exit(zero cannot be stored in binary tree) : ";
    cin >> item;

    while(item != 0)
    {
        //for first node
        if (root==NULL)
        {
            root = new Node;
            root->data = item;
            root->right = NULL;
            root->left = NULL;
        }

        //for any other node
        else
        {
            q = new Node;
            q->data = item;
            q->left = NULL;
            q->right = NULL;
            p = root;

            while (p != NULL)
            {
                p1 = p;

                if (item >= p->data)
                    p = p->right;
                else
                    p = p->left;
            }

            if (item >= p1->data)
                p1->right = q;
            else
                p1->left = q;
        }
        cout << "Enter data to be inserted otherwise, enter zero(zero cannot be inserted in binary tree) : ";
        cin >> item;
    } 
}

//traverses and prints binary search tree in preorder using recurssion
void BinarySearchTree::recursive_preorder(Node *temp)
{
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        recursive_preorder(temp->left);
        recursive_postorder(temp->right);
    }
}

//traverses and prints binary search tree in postorder using recurssion
void BinarySearchTree::recursive_postorder(Node* temp)
{
    while (temp != NULL)
    {
        recursive_postorder(temp->left);
        recursive_postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

//traverses and prints binary search tree in inorder using recurssion
void BinarySearchTree::recursive_inorder(Node* temp)
{
    while (temp != NULL)
    {
        recursive_inorder(temp->left);
        cout << temp->data <<" ";
        recursive_inorder(temp->right);
    }
}

//counts no. of leaves in the tree
void BinarySearchTree::count_leaf(Node *temp, int count=0)
{
    if (temp != NULL)
    {
        if (temp->right == NULL && temp->left == NULL)
            count++;

        count_leaf(temp->right, count);
        count_leaf(temp->left, count);
    }
}

int main()
{
    char ch; int c; BinarySearchTree B;
    do
    {
        system("cls");
        cout << "\t\t\tMENU DRIVEN PROGRAM TO IMPLEMENT DIFFERENT OPERATIONS OF BINARY SEARCH TREE\n";
        cout << "\n1. Insert";
        cout << "\n2. Print tree in preorder(recursive)";
        cout << "\n3. Print tree in postorder(recursive)";
        cout << "\n4. Print tree in inorder(recursive)";
        cout << "\n5. Count no. of leaves.";
        cout << "\nEnter your choice : ";
        cin >> c;

        switch (c)
        {
        case 1: B.insert();
            break;
        case 2: B.recursive_preorder(root);
            break;
        case 3: B.recursive_postorder(root);
            break;
        case 4: B.recursive_inorder(root);
            break;
        case 5: B.count_leaf(root);
            break;
        default: cout << "INVALID INPUT. TRY AGAIN";
        }
        cout << "\nDo you wan to revisit the menu(press y/n) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
 }
