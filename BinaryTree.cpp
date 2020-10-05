//The menu drievn program implements different operations in a binary search tree.

#include <iostream>
#include<stdio.h>

using namespace std;

#define size 10
int count1 = 0;

//structure of node
struct Node
{
    int data;
    Node* left;
    Node* right;
}*root=NULL;

//Stack
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

//Queue
class Queue
{
    Node* arr[size];
    int front, rear;
public:
    Queue();
    void enqueue(Node* data);
    Node* dequeue();
    int isEmpty();
};

//Binary Tree
class BinarySearchTree
{
    Node *p, *q, *p1;

public:

    BinarySearchTree();
    void insert();
    void recursive_preorder(Node*);
    void recursive_postorder(Node*);
    void recursive_inorder(Node*);
    void iterative_preorder(Node*);
    void iterative_postorder(Node*);
    void iterative_inorder(Node*);
    void search_tree(Node*, int);
    void bfs_traversal(Node*);
    int count_leaf(Node*);
    int count_nonleaf(Node*);
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
    Node* a=NULL;
    if (isempty())
        cout << "Underflow.";
    else
    {
        a = arr[top];
        top--;
    }
    return a;
}

//constructor for queue
Queue::Queue()
{
    front = rear = -1;
}

//checks if queue is empty
int Queue::isEmpty()
{
    if (rear == -1)
        return 1;
    else
        return 0;
}

//inserts an element in queue
void Queue::enqueue(Node* data)
{
    if (isEmpty())
    {
        front++;
        arr[++rear] = data;
    }
    else
        if (rear == size - 1)
            cout << "Overflow.";
        else
            arr[++rear] = data;
}

//deletes an element from queue
Node* Queue::dequeue()
{
    Node* ptr = NULL;
    //if queue is empty
    if (isEmpty())
        cout << "Underflow.";
    //if queue contains single node
    else
        if (front == rear)
        {
            ptr = arr[front];
            front = rear = -1;
        }
    //for every other node
        else
        {
           ptr = arr[front];
            front++;
        }

    return ptr;
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
    if (temp != NULL)
    {
        cout<<temp->data<<" ";
        recursive_preorder(temp->left);
        recursive_postorder(temp->right);
    }
}

//traverses and prints binary search tree in postorder using recurssion
void BinarySearchTree::recursive_postorder(Node* temp)
{
    if (temp != NULL)
    {
        recursive_postorder(temp->left);
        recursive_postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

//traverses and prints binary search tree in inorder using recurssion
void BinarySearchTree::recursive_inorder(Node* temp)
{
    if (temp != NULL)
    {
        recursive_inorder(temp->left);
        cout << temp->data <<" ";
        recursive_inorder(temp->right);
    }
}


//traverses the tree in preorder using iteration
void BinarySearchTree::iterative_preorder(Node* temp)
{
    stack S;
    if (temp != NULL)
    {
        S.push(temp);
        while (!S.isempty())
        {
            temp = S.pop();
            cout << temp->data << " ";
            if (temp->right != NULL)
                S.push(temp->right);
            if (temp->left != NULL)
                S.push(temp->left);
        }
    }
       
}
//traverses and prints binary search tree in postorder using iteration
void BinarySearchTree::iterative_postorder(Node* temp)
{
    stack S;
    q = temp;

    while (temp != NULL)
    {
        for (; temp->left != NULL; temp = temp->left)
        {
            S.push(temp);
        }

        while (temp != NULL && (temp->right == NULL || temp->right == q))
        {
            cout << temp->data << " ";
            q = temp;

            if (S.isempty())
                return;
            temp = S.pop();
        }

        S.push(temp);
        temp = temp->right;
    }
}

//traverses and prints binary search tree in inorder using iteration
void BinarySearchTree::iterative_inorder(Node* temp)
{
    stack S;

    while (temp != NULL)
    {
        while (temp != NULL)
        {
            if (temp->right != NULL)
            {
                S.push(temp->right);
            }
            S.push(temp);
            temp = temp->left;
        }
        temp = S.pop();

        while (!S.isempty() && temp->right == NULL)
        {
            cout << temp->data << " ";
            temp = S.pop();
        }
        cout << temp->data << " ";

        if (!S.isempty())
            temp = S.pop();

        else
            temp = NULL;
    }
    
}

//counts no. of leaves in the tree
int BinarySearchTree::count_leaf(Node* temp)
{
    if (temp != NULL)
    {

        if ((temp->left == NULL) &&  (temp->right == NULL))
            count1++;

        count_leaf(temp->left);
        count_leaf(temp->right);
    }

    return count1;
}

//counts no. of non-leaf nodes in the tree
int BinarySearchTree::count_nonleaf(Node* temp)
{
    if (temp == NULL || (temp->left == NULL && temp->right == NULL)) {
        return 0;
    }

    return 1 + count_nonleaf(temp->left) + count_nonleaf(temp->right);
}

//searches an element in the tree
void BinarySearchTree::search_tree(Node *temp, int item)
{
    int flag = 0;

    while (temp != NULL)
    {
        if (item == temp->data)
        {
            flag = 1;
            break;
        }
        else if (item < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (flag == 0)
        cout << "Node not found.";
    else
        cout << "Element found.";
}

//prints bfs traversal for the tree
void BinarySearchTree::bfs_traversal(Node* temp)
{
    Queue Q;
    if (temp != NULL)
    {
        Q.enqueue(temp);
        while (!Q.isEmpty())
        {
            temp = Q.dequeue();
            cout << temp->data << " ";

            if (temp->left != NULL)
                Q.enqueue(temp->left);
                
            if (temp->right != NULL)
                Q.enqueue(temp->right);
            
        }
    }
}

int main()
{
    char ch; int c; BinarySearchTree B; int c1, c2;
    do
    {
        system("cls");
        cout << "\t\t\tMENU DRIVEN PROGRAM TO IMPLEMENT DIFFERENT OPERATIONS OF BINARY SEARCH TREE\n";
        cout << "\n1. Insert";
        cout << "\n2. Print tree in preorder(recursive)";
        cout << "\n3. Print tree in postorder(recursive)";
        cout << "\n4. Print tree in inorder(recursive)";
        cout << "\n5. Print tree in preorder(iterative)";
        cout << "\n6. Print tree in postorder(iterative)";
        cout << "\n7. Print tree in inorder(iterative)";
        cout << "\n9. Count no. of leaf nodes, non-leaf nodes and total no. of nodes in the tree";
        cout << "\n10. Search in tree";
        cout << "\n11. Print BFS traversal";
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
        case 5: B.iterative_preorder(root);
            break;
        case 6: B.iterative_postorder(root);
            break;
        case 7: B.iterative_inorder(root);
            break;
        case 8: c1 = B.count_leaf(root);
                c2 = B.count_nonleaf(root);
                cout << "\nLeaf nodes : " << c1;
                cout << "\nNon-leaf nodes : " << c2;
                cout << "\nTotal nodes : " << c1 + c2;
            break;
        case 9: int item;
                 cout << "Enter node to be searched : ";
                 cin >> item;
                 B.search_tree(root,item);
            break;
        case 10: B.bfs_traversal(root);
            break;
        default: cout << "INVALID INPUT. TRY AGAIN";
        }
        cout << "\nDo you wan to revisit the menu(press y/n) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
 }