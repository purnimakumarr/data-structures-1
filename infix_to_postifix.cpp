#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

class node
{
public :
    node *next;
    char data;
};

class Stack
{
    node *top, *temp;

public:
    void push(char);
    void pop();
    int isempty();
    void display();
    int getTop();
    void infix_to_postfix(string);
    int precedence(char);
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

void Stack :: push(char item)
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

int Stack :: getTop()
{
    return top->data;
}

int Stack :: precedence(char ch)
{
    if(ch=='+' || ch=='-')
        return 0;
    else
        if(ch=='*' || ch=='/' || ch=='%' )
            return 1;
    else
        if(ch=='^')
            return 2;
    else return -1;
}

void Stack :: infix_to_postfix(string exp)
{
    string new_str;
    for(int i=0; i<exp.length(); ++i)
    {

        if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
        {
            new_str+=exp[i];
        }

        else
            if(exp[i]=='(')
               push('(');

        else
            if(exp[i]==')')
        {
            while(!isempty() && getTop()!='(')
            {
                char c=getTop();
                pop();
                new_str+=c;
            }
            if(getTop()== '(')
            {
                char c=getTop();
                pop();
            }
        }

        else
        {
            while(!isempty() && precedence(exp[i])<=precedence(getTop()))
            {
                char c=getTop();
                pop();
                new_str+=c;
            }
            push(exp[i]);
        }

        while(!isempty())
        {
            char c=getTop();
            pop();
            new_str+=c;
        }
    }

    cout<<"Postfix expression : "<<new_str;
}

int main()
{
     Stack obj;
    char arr[30];

    cout<<"Enter infix expression expression : ";
    gets(arr);

    obj.infix_to_postfix( arr);

    return 0;
}
