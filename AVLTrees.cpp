/*
Write a program to implement AVL Trees. Perform following operations:
(i) Insertion
(ii) Deletion
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

//global declarations
enum class type{R_0, R_1, R_neg1, L_0, L_1, L_neg1, null};
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
	void deletion(Node*, int);
    void delc(Node*&);
    int get_height(Node*);
    void calculate_bf(Node*);
    void balance_tree_after_insertion(Node*);
    void balance_tree_after_deletion(Node*, type);
    void right_rotate(Node*);
    void left_rotate(Node*);
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
            balance_tree_after_insertion(q);
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

//balances the tree after insertion
void AVLTree::balance_tree_after_insertion(Node* temp)
{
    int flag = 0;
    //calculating the height and balanced factor of all the nodes since it might be changed due to insertion of new node
    root->height=get_height(root);
    calculate_bf(root);

    for (Node* temp1 = temp->parent; temp1 != NULL; temp1 = temp1->parent)
        if (temp1->bf < -1 || temp1->bf > 1)
        {
            p = temp1;
            flag = 1;
            break;
        }
   
    if (flag == 1)
    {
        //right child, right subtree
        if (p->bf == 2 && p->right->bf == 1)
            left_rotate(p);
        //right child, left subtree
        else if (p->bf == 2 && p->right->bf == -1)
        {
            right_rotate(p->right);
            left_rotate(p);

        }
        //left child, right subtree
        else if (p->bf == -2 && p->left->bf == 1)
        {
            left_rotate(p->left);
            right_rotate(p);
        }
        //left child, left subtree
        else if (p->bf == -2 && p->left->bf == -1)
            right_rotate(p);

        root->height = get_height(root);
        calculate_bf(root);
    } 
}

//left rotation
void AVLTree::left_rotate(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    if(y->left!=NULL)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

//right rotation
void AVLTree::right_rotate(Node *x)
{
    Node* y = x->left;
    x->left = y->right;
    if(y->right!=NULL)
        y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;

}

//traverses and prints binary search tree in inorder using recurssion
void AVLTree::recursive_inorder(Node* temp)
{
    if (temp != NULL)
    {
        recursive_inorder(temp->left);
        cout << "Data : "<<temp->data << "\t" << "Height : " << temp->height <<"\t"<< "Balance Factor : " << temp->bf;
        cout << endl;
        recursive_inorder(temp->right);
    }
}

void AVLTree::deletion(Node* temp, int item)
{
    Node* prev = NULL;

    //search the node we want to delete
    while (temp != NULL)
    {
        if (item == temp->data)
            break;

        prev = temp; //stores address of previous/parent node
        if (item < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp != NULL && temp->data == item)
    {
        //for root node
        if (temp == root)
            delc(root);
        //for all other nodes
        else if (prev->left == temp)
            delc(prev->left);
        else
            delc(prev->right);
    }
    else if (root != NULL)
        cout << "\nKey not found.";
    else
        cout << "\nAVL Tree Empty.";
}

void AVLTree::delc(Node*& temp1)
{
    Node* tmp = temp1, * prev;
    type rotation;

    //if a node has single or no child
    if (temp1->right == NULL)
        temp1 = temp1->left;
    else if (temp1->left == NULL)
        temp1 = temp1->right;

    //if a node having 2 children is deleted
    else
    {
        tmp = temp1->left;
        prev = temp1;

        while (tmp->right != NULL)
        {
            prev = tmp;
            tmp = tmp->right;
        }

        temp1->data = tmp->data;

        if (prev == temp1)
            prev->left = tmp->left;
        else
            prev->right = tmp->right;
    }

    rotation = type::null;
    if (tmp == tmp->parent->right)
    {
        //R(0)
        if (tmp->parent->left->bf == 0)
            rotation = type::R_0;
        //R(-1)
        else if (tmp->parent->left->bf == -1)
            rotation = type::R_neg1;
        //R(1)
        else if (tmp->parent->left->bf == 1)
            rotation = type::R_1;

    }
    else if (tmp == tmp->parent->left)
    {
        //L(0)
        if (tmp->parent->right->bf == 0)
            rotation = type::L_0;
        //L(-1)
        else if (tmp->parent->right->bf == -1)
            rotation = type::L_neg1;
        //L(1)
        else if (tmp->parent->right->bf == 1)
            rotation = type::L_1;

    }
    Node* r = tmp->parent;
    delete tmp;
    balance_tree_after_deletion(r, rotation);
}

//balances the tree after deletion
void AVLTree::balance_tree_after_deletion(Node* temp, type rotation)
{
    root->height = get_height(root);
    calculate_bf(root);

    int flag = 0;
    for (Node* temp1 = temp; temp1 != NULL; temp1 = temp1->parent)
        if (temp1->bf < -1 || temp1->bf > 1)
        {
            p = temp1;
            flag = 1;
            break;
        }

    if (flag == 1)
    {
        if (rotation == type::R_0)
            right_rotate(p);
        else if (rotation == type::R_neg1)
            right_rotate(p);
        else if (rotation == type::R_1)
        {
            left_rotate(p->left);
            right_rotate(p);
        }
        else if (rotation == type::L_0)
            left_rotate(p);
        else if(rotation == type::L_1)
            left_rotate(p);
        else
        {
            right_rotate(p->right);
            left_rotate(p);
        }
    }

    root->height = get_height(root);
    calculate_bf(root);

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
        case '2': int item;
            cout << "Enter item you want to delete : ";
            cin >> item;
            obj.deletion(root, item);
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
