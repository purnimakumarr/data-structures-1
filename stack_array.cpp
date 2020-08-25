#include<iostream>
#include<stdlib.h>

using namespace std;

#define size 5

template <class X>
class stack
{
    X arr[size];
    int top;
public:
    void push(X);
    void pop();
    void display();
    int isempty();
    X get_top();
    void clear();
    stack();
};

template <class X>
stack<X> :: stack()
{
    top=-1;
}

template <class X>
int stack<X> :: isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

template <class X>
void stack<X> :: push(X item)
{
    if(top==size-1)
        cout<<"Overflow.";
    else
        arr[++top]=item;
}

template <class X>
void stack<X> :: pop()
{
    if(isempty())
        cout<<"Underflow.";
    else
    {
        cout<<"Element deleted : "<<arr[top];
        top--;
    }
}

template <class X>
void stack<X> :: display()
{
    if(isempty())
        cout<<"Stack is empty.";
    else
    {
        int temp=top;
        cout<<"Stack : ";
        while(temp>=0)
        {
            cout<<arr[temp]<<" ";
            temp--;
        }
    }
}

template <class X>
void stack<X> :: clear()
{
    if(isempty())
        cout<<"Stack is already empty.";
    else
    {
        while(top>=0)
        {
            top--;
        }
        cout<<"Stack is cleared.";
    }
}

template<class X>
X stack<X> :: get_top()
{
    return arr[top];
}
int main()
{
    stack<int> obj; char ch; int data;

    do
    {
        system("cls");
        cout<<"MENU TO PERFORM OPERATIONS ON STACK USING ARRAY IMPLEMENTATION.\n";
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
