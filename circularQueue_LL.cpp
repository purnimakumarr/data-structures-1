#include<iostream>
#include<stdlib.h>

using namespace std;

class QueueLL
{
    struct node
    {
        int data;
        node *next;
    }*top, *newptr;
public:
    QueueLL();
    ~QueueLL();
    void enqueue(int data);
    void dequeue();
    void display();
    void clear();
    int getData();
    int isEmpty();
};

QueueLL :: QueueLL()
{
    top=NULL;
}

QueueLL :: ~QueueLL()
{
    node *p=top;
    while(!isEmpty())
    {
        p=top->next;
        delete top;
        top=p;
    }
}

void QueueLL :: enqueue(int data)
{
    //declaring new node
    newptr=new node;
    newptr->data=data;

    //for first node
    if(isEmpty())
    {
        newptr->next=top;
        top=newptr;
    }
    //for every other node
    else
    {
        newptr->next=top->next;
        top->next=newptr;
        top=newptr;
    }
}

void QueueLL :: dequeue()
{
    //if queue is empty
    if(isEmpty())
        cout<<"Queue is empty.";
    //for single node in queue
    else
        if(top==top->next)
    {
        newptr=top;
        cout<<"Item deleted with data : "<<newptr->data;
        delete newptr;
        top=NULL;
    }
    //for every other node in queue
    else
    {
        newptr=top->next;
        cout<<"Item deleted with data : "<<newptr->data;
        top->next=newptr->next;
        delete newptr;
    }
}

void QueueLL :: display()
{
    //if queue is empty
    if(isEmpty())
        cout<<"Queue is empty.";
    else
    {
        newptr=top->next;
        cout<<"Queue : ";
        do
        {
            cout<<newptr->data<< " ";
            newptr=newptr->next;
        }while(newptr!=top->next);
    }
}

int QueueLL :: getData()
{
    //if queue is empty
    if(isEmpty())
        return 0;
    //return top most element
    else
        return top->data;
}

void QueueLL :: clear()
{
    //if queue is empty
    if(isEmpty())
        cout<<"Queue is empty.Nothing to clear.";
    //clearing the queue
    else
    {
        while(!isEmpty())
        {
            dequeue();
        }
        cout<<"Queue is cleared.";
    }
}

int QueueLL :: isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int main()
{
    QueueLL q; char ch;

    do
    {
        system("cls");
        cout<<"MENU TO PERFORM OPERATIONS ON CIRCULAR QUEUE (LINKED LIST IMPLEMENTATION)";
        cout<<"\n1.Enqueue";
        cout<<"\n2.Dequeue";
        cout<<"\n3.Display";
        cout<<"\n4.Clear";
        cout<<"\n5.Return top most element.";
        cout<<"\nInput choice : ";
        cin>>ch;

        switch(ch)
        {
            case '1' :  int data;
                        cout<<"Enter data : ";
                        cin>>data;
                        q.enqueue(data);
                        break;

            case '2' :  q.dequeue();
                        break;

            case '3' :  q.display();
                        break;

            case '4' :  q.clear();
                        break;

            case '5' :  int a;
                        a=q.getData();
                        if(a!=0)
                            cout<<"Top most element is : "<<a;
                        else
                            cout<<"Queue is empty.";
                        break;

            default  :  cout<<"Invalid Input.";
        }
        cout<<"\nDo you want to continue(press y/n) : ";
        cin>>ch;
    }while(toupper(ch)=='Y');
    return 0;
}


