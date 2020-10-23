/*
Write a program to implement AVL Trees. Perform following operations:
(i) Insertion
(ii) Deletion
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

//only for formatting
void print()
{
    cout << endl;
    for (int i = 0; i <= 119; i++)
        cout << "-";
    cout << endl;
}
//structure of node
struct Node
{
	Node *left, *right, *parent;
	int data, bf, height;
}*root=NULL;

class AVLTree
{
    Node* p, * q, * p1, * r;
public:
	AVLTree();
	void insertion();
	void deletion();
    int get_height(Node*);
    void calculate_bf(Node*);
    void balance_tree(Node*);
    void right_rotate(Node*, Node*);
    void left_rotate(Node*, Node*);
    void recursive_inorder(Node*);
};

AVLTree::AVLTree()
{
	p = NULL;
	q = NULL;
    p1 = NULL;
    r = NULL;
}

//inserting a node in a AVL Tree
void AVLTree::insertion()
{
    int item;
    cout << "Enter data to be inserted, otherwise enter zero to exit(zero cannot be stored in binary tree) : ";
    cin >> item;

    while (item != 0)
    {
        //for first node
        if (root == NULL)
        {
            root = new Node;
            root->data = item;
            root->right = NULL;
            root->left = NULL;
            root->height=get_height(root);
            root->bf = 0;
            root->parent = NULL;
        }

        //for any other node
        else
        {
            q = new Node;
            q->data = item;
            q->left = NULL;
            q->right = NULL;
            q->bf = 0;
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

            q->parent = p1;

            //checks if tree is balance or not, if not then balance the tree using rotations
            balance_tree(q);
        }
        cout << "Enter data to be inserted otherwise, enter zero(zero cannot be inserted in binary tree) : ";
        cin >> item;
    }
}

//return height of each node in the tree
int AVLTree::get_height(Node* temp)
{
    if (temp == NULL)
        return 0; //if node is NULL returns zero
    else
    {
        //evaluates depth for right subtrees
        int right_depth = get_height(temp->right);
        if (temp->right != NULL)
            temp->right->height = right_depth;

        //evaluates depth for left subtrees
        int left_depth = get_height(temp->left);
        if (temp->left != NULL)
            temp->left->height = left_depth;

        //the maximum depth is taken into account and then 1 is added for the root node
        if (right_depth > left_depth)
            return right_depth + 1;
        else
            return left_depth + 1;
    }
}

//calculates balance factor of all nodes
void AVLTree::calculate_bf(Node* temp)
{
    if (temp != NULL)
    {
        if (temp->right != NULL && temp->left != NULL)
            temp->bf = (temp->right->height) - (temp->left->height);
        else if (temp->left != NULL)
            temp->bf = -(temp->left->height);
        else if (temp->right != NULL)
            temp->bf = temp->right->height;
        else
            temp->bf = 0;

        calculate_bf(temp->right);
        calculate_bf(temp->left);
    }
}

//checks if a tree is balance or not, if not then balances th tree using rotations
void AVLTree::balance_tree(Node* temp)
{
    int flag = 0;
    //calculating the height and balanced factor of all the nodes since it might be changed due to insertion of new node
    root->height=get_height(root);
    calculate_bf(root);

    for (Node* temp1 = temp->parent; temp1 != NULL; temp1 = temp1->parent)
        if (temp1->bf < -1 || temp1->bf>1)
        {
            p = temp1;
            //right child
            if (temp->data >= p->data)
                q = p->right;
            //left child
            else
                q = p->left;
            flag = 1;
            break;
        }
   
    if (flag == 1)
    {
        r = temp->parent; //immediate parent
        if (q == p->right)
        {
            //right subtree
            if (temp->data >= q->data)
                left_rotate(q, p);
            else
            {
                right_rotate(r, q);
                left_rotate(r, p);
            }
        }
        else if (q == p->left)
        {
            //right subtree
            if (temp->data >= q->data)
            {
                right_rotate(r, q);
                left_rotate(r, p);
            }
            //left subtree
            else
                right_rotate(q, p);
        }

        root->height = get_height(root);
        calculate_bf(root);
    } 
}

//left rotation
void AVLTree::left_rotate(Node* q, Node* p)
{
    p->right = q->left;
    q->left->parent = p;
    q->parent = p->parent;

    if (p->parent == NULL)
        root = q;
    else if (p == p->parent->left)
        p->parent->left = q;
    else
        p->parent->right = q;

    q->left = p;
    p->parent = q;
}

//right rotation
void AVLTree::right_rotate(Node* q, Node *p)
{
    p->left = q->right;
    q->right->parent = p;
    q->parent = p->parent;

    if (p->parent == NULL)
        root = q;
    else if (p == p->parent->right)
        p->parent->right = q;
    else
        p->parent->left = q;

    q->right = p;
    p->parent = q;

}

//traverses and prints binary search tree in inorder using recurssion
void AVLTree::recursive_inorder(Node* temp)
{
    if (temp != NULL)
    {
        recursive_inorder(temp->left);
        cout << "Data : "<<temp->data << " " << "Height : " << temp->height <<" "<< "Balance Factor : " << temp->bf;
        cout << endl;
        recursive_inorder(temp->right);
    }
}


int main()
{
	AVLTree obj; char ch;
	do
	{
        system("cls");
        print();
		cout << "\t\t\tMENU DRIVEN PROGRAM TO PERFORM CERTAIN FUNCTIONS ON AVL TREES";
        print();
		cout << "\n1. Insertion";
		cout << "\n2. Deletion";
        cout << "\n3. Print Inorder Traversal";
		cout << "\nEnter choice : ";
		cin >> ch;

		switch (ch)
		{
		case '1': obj.insertion();
			break;
		case '2':
			break;
        case '3': cout << "\nAVL Tree (Node Details) :-\n";
            obj.recursive_inorder(root);
            break;
		default: cout << "\nINVALID INPUT";
		}
        cout << "\nDo you want to continue? : ";
        cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	return 0;
}
