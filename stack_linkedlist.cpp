#include<iostream>
#include<stdlib.h>

using namespace std;

template <class X>
class node
{
public :
    node *next;
    X data;
};

template <class X>
class Stack
{
    node<X> *top=NULL, *temp;

public:
    void push(X);
    void pop();
    int isempty();
    void display();
    X get_top();
    void clear();
    Stack();
    ~Stack();
};

template <class X>
Stack<X> :: Stack()
{
    top=NULL;
}

template <class X>
Stack<X> :: ~Stack()
{
    temp=top;
    while(!isempty())
    {
        temp=top->next;
        delete top;
        top=temp;
    }
    delete temp;
}
template <class X>
int Stack<X> :: isempty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
template <class X>
void Stack<X> :: push(X item)
{
    temp=new node<X>;
    temp->data=item;
    temp->next=top;
    top=temp;
}

template <class X>
void Stack<X> :: pop()
{
    if(isempty())
        cout<<"Underflow.";
    else
    {
        temp=top;
        cout<<"Element deleted : "<<temp->data;
        top=top->next;
        delete temp;
    }
}

template <class X>
void Stack<X> :: display()
{
    if(isempty())
        cout<<"Stack is empty.";
    else
    {
        temp=top;
        cout<<"Stack : ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

template <class X>
X Stack<X> :: get_top()
{
    return top->data;
}

template <class X>
void Stack<X> :: clear()
{
    if(isempty())
        cout<<"Stack is already empty.";
    else
    {
        while(!isempty())
        {
            temp=top->next;
            delete top;
            top=temp;
        }
    }
}
int main()
{
    Stack<int> obj; char ch; int data;

    do
    {
        system("cls");
        cout<<"MENU TO PERFORM OPERATIONS ON STACK USING LINKED LIST IMPLEMENTATION.\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Clear\n";
        cout<<"4. Display\n";
        cout<<"5. Print top element of the stack\n";
        cout<<"Input choice : ";
        cin>>ch;

        switch(ch)
        {
            case '1' :  cout<<"Input data to be stored in stack : ";
                        cin>>data;
                        obj.push(data);
                        break;

            case '2' :  obj.pop();
                        break;

            case '3' :  obj.clear();
                        break;

            case '4' :  obj.display();
                        break;

            case '5' :  cout<<"Item at the top of stack : "<<obj.get_top();
                        break;

            default :   cout<<"Invalid Input.\n";
        }
        cout<<"\nDo you want to continue(press y/n) : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}
