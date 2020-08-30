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
    void push(int);
    void pop();
    int isempty();
    void display();
    char getTop();
    int match_delimiter(string);
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

char Stack :: getTop()
{
    return top->data;
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

int Stack :: match_delimiter(string s)
{
    char ch;
    for(int i=0; i<s.length(); i++)
    {
        //if there is an opening bracket then push it into the stack
        if(s[i]=='(' || s[i]== '[' || s[i]=='{')
            push(s[i]);

        //if the delimiter is not an opening bracket, it must be a closing bracket and stack should not be empty
        if(isempty())
            return 0;

        switch(s[i])
        {
            case ')' :  ch=getTop();
                        pop();

                        //if the delimiter in the stack is not an opening round bracket, exp is not balanced
                        if(ch=='{' || ch=='[')
                            return 0;
                        break;

            case '}' :  ch=getTop();
                        pop();

                        //if the delimiter in the stack is not an opening curly bracket then the exp is not balanced
                        if(ch=='(' || ch=='[')
                            return 0;
                        break;

            case ']' :  ch==getTop();
                        pop();

                        //if the delimiter in the stack is not a square opening bracket then the exp is not balanced
                        if(ch=='(' || ch=='{')
                            return 0;
                        break;

        }
    }
    //check empty stack
    return(isempty());
}

int main()
{
    string exp; Stack obj;
    cout<<"Enter the expression : ";
    cin>>exp;
    if(obj.match_delimiter(exp))
        cout<<"Expression is balanced.";
    else
        cout<<"Expression is not balanced.";

    return 0;
}
