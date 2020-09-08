#include<iostream>
#include<stdlib.h>

using namespace std;

class QueueUsingStack
{
    struct node
    {
        int data;
        node *next;
    }*top, *temp;
public:
    QueueUsingStack();
    ~QueueUsingStack();
    void enqueue(QueueUsingStack&, int);
    int dequeue();
    void display();
    void push(int);
    int pop();
    int isEmpty();
};

//constructor
QueueUsingStack :: QueueUsingStack()
{
        top=NULL;
}

//destructor
QueueUsingStack :: ~QueueUsingStack()
{
    node *p=top;
    while(!isEmpty())
    {
        p=top->next;
        delete top;
        top=p;
    }
}

void QueueUsingStack :: enqueue(QueueUsingStack &s, int item)
{

    while(!isEmpty())
    {
        int x=pop();
        s.push(x);
    }

    push(item);

    while(!s.isEmpty())
    {
        int x=s.pop();
        push(x);
    }
}

int QueueUsingStack :: dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is empty.";
        return 0;
    }
    else
    {
        int x=pop();
        return x;
    }
}

void QueueUsingStack :: display()
{
    temp=top;
    if(isEmpty())
        cout<<"Queue is empty.";
    else
    {
        cout<<"Queue : ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
void QueueUsingStack :: push(int item)
{
    temp=new node;
    temp->data=item;
    temp->next=top;
    top=temp;
}

int QueueUsingStack :: pop()
{
    int x;

    x=top->data;
    temp=top;
    top=top->next;
    delete temp;

    return x;
}

int QueueUsingStack :: isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    QueueUsingStack s1, s2; char ch;

    do
    {
        system("cls");
        cout<<"MENU TO IMPLEMENT QUEUES USING STACKS.\n";
        cout<<"1. Enqueue.\n";
        cout<<"2. Dequeue.\n";
        cout<<"3. Display.\n";
        cout<<"Enter choice : ";
        cin>>ch;

        switch(ch)
        {
            case '1' :  int item;
                        cout<<"Input data : ";
                        cin>>item;
                        s1.enqueue(s2, item);
                        break;

            case '2' :  item=s1.dequeue();
                        if(item!=0)
                            cout<<"Data deleted : "<<item;
                        break;

            case '3' :  s1.display();
                        break;

            default  :  cout<<"\nInvalid Input.";
        }
        cout<<"\nDo you want to continue : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}
