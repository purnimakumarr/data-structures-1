#include<iostream>
#include<string.h>
#include<stdio.h>

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
    int getTop();
    int evaluate(char*);
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

int Stack :: getTop()
{
    return top->data;
}

int Stack :: evaluate(char *exp)
{
    for(int i=0; exp[i]; ++i)
    {
        if(exp[i]==' ')
            continue;

        else if(isdigit(exp[i]))
        {
            int num=0;
            while(isdigit(exp[i]))
            {
                num=num*10+(int)(exp[i] -  '0');
                i++;
            }
            i--;
            push(num);
        }

        else
        {
            int a=getTop();
            pop();
            int b=getTop();
            pop();

            switch(exp[i])
            {
                case  '+' :    push(b+a);
                                break;

                case  '-' :    push(b-a);
                                break;

                case  '*' :    push(b*a);
                                break;

                case  '/' :    push(b/a);
                                break;
            }
        }
    }
    return getTop();
}

int main()
{
     Stack obj;
    char arr[30];

    cout<<"Enter postfix expression : ";
    gets(arr);

    int res=obj.evaluate(arr);
    cout<<"Result : "<<res;

    return 0;
}
