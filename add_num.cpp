#include<iostream>

using namespace std;

class node
{
public :
    node *next;
    int data;
};

class Stack
{
    node *top, *temp;

public:
    void push(int);
    void pop();
    int isempty();
    void display();
    Stack add_num(Stack &,Stack &);
    Stack();
    ~Stack();
};

Stack :: Stack()
{
    top=NULL;
}

Stack :: ~Stack()
{
    temp=top;
    while(!isempty())
    {
	temp=top->next;
	delete top;
	top=temp;
    }
}

int Stack :: isempty()
{
    if(top==NULL)
	return 1;
    else
	return 0;
}

void Stack :: push(int item)
{
    temp=new node;
    temp->data=item;
    temp->next=top;
    top=temp;
}

void Stack :: pop()
{
    if(isempty())
	cout<<"Underflow.";
    else
    {
	temp=top;
	top=top->next;
	delete temp;
    }
}

void Stack :: display()
{
    if(isempty())
	cout<<"Stack is empty.";
    else
    {
	temp=top;
	while(temp!=NULL)
	{
	    cout<<temp->data;
	    temp=temp->next;
	}
    }
}

Stack Stack :: add_num(Stack &a, Stack &b)
{
    int carry=0,res;
    while(!(a.isempty() && b.isempty()))
    {
        res=a.top->data+b.top->data+carry;
        carry=res/10;
        push(res%10);
        a.pop();
        b.pop();
    }
    return *this;
}

int main()
{
    int ch; Stack obj1, obj2, obj3; int n, j;

    cout<<"Enter no. of digits in first number : ";
    cin>>n;
    cout<<"Enter number : ";
    for(int i=0; i<n; i++)
    {
	cin>>j;
	obj1.push(j);
    }

    cout<<"Enter no. of digits in second number : ";
    cin>>n;
    cout<<"Enter number : ";
    for(int i=0; i<n; i++)
    {
	cin>>j;
	obj2.push(j);
    }

    obj3.add_num(obj1, obj2);
    cout<<"The addition of numbers : ";
    obj3.display();

    return 0;
}

