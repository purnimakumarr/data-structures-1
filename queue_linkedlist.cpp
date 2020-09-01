#include<iostream>
#include<stdlib.h>

using namespace std;

class QueueLL
{
    struct node
    {
        int data;
        node *next;
    }*front, *rear, *newptr;
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
    front=rear=NULL;
}

QueueLL :: ~QueueLL()
{
    node *p=front;
    while(!isEmpty())
    {
        p=front->next;
        delete front;
        front=p;
    }
}

void QueueLL :: enqueue(int data)
{
    //declaring new node
    newptr=new node;
    newptr->data=data;
    newptr->next=NULL;

    //for first node
    if(isEmpty())
    {
        front=rear=newptr;
    }
    //for every other node
    else
    {
        rear->next=newptr;
        rear=newptr;
    }
}

void QueueLL :: dequeue()
{
    //if queue is empty
    if(isEmpty())
        cout<<"Queue is empty.";
    //for single node in queue
    else
        if(rear==front)
    {
        newptr=front;
        cout<<"Item deleted with data : "<<newptr->data;
        delete newptr;
        rear=front=NULL;
    }
    //for every other node in queue
    else
    {
        newptr=front;
        cout<<"Item deleted with data : "<<newptr->data;
        front=front->next;
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
        newptr=front;
        cout<<"Queue : ";
        while(!isEmpty())
        {
            cout<<newptr->data<< " ";
            newptr=newptr->next;
        }
    }
}

int QueueLL :: getData()
{
    //if queue is empty
    if(isEmpty())
        return 0;
    //return top most element
    else
        return front->data;
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
    if(front==NULL)
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
        cout<<"MENU TO PERFORM OPERATIONS ON LINEAR QUEUE (LINKED LIST IMPLEMENTATION)";
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

