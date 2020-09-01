#include<iostream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define size 5

class Queue
{
    int arr[size], front, rear;
public:
    Queue();
    void enqueue(int data);
    void dequeue();
    int getData();
    void clear();
    void display();
    int isEmpty();
};

Queue :: Queue()
{
    front=rear=-1;
}

int Queue :: isEmpty()
{
    if(rear==-1)
        return 1;
    else
        return 0;
}
void Queue :: enqueue(int data)
{
    if(isEmpty())
    {
        front++;
        arr[++rear]=data;
    }
    else
        if(rear==size-1)
            cout<<"Overflow.";
    else
        arr[++rear]=data;
}

void Queue :: dequeue()
{
    //if queue is empty
    if(isEmpty())
        cout<<"Underflow.";
    //if queue contains single node
    else
        if(front==rear)
    {
        cout<<"\nItem deleted with data : "<<arr[front];
        front=rear=-1;
    }
    //for every other node
    else
    {
        cout<<"\nItem deleted with data : "<<arr[front];
        front++;
    }
}

void Queue :: clear()
{
    //id queue is empty
    if(isEmpty())
        cout<<"Queue is already empty. Nothing to clear.";
    //deleting all nodes
    else
    {
        while(!isEmpty())
        {
            dequeue();
        }
        cout<<"Queue is cleared.";
    }
}

void Queue :: display()
{
    ///if queue is empty
    if(isEmpty())
        cout<<"Queue is empty.";
    //print the queue
    else
    {
        cout<<"Queue : ";
        for(int i=front; i<=rear; i++)
            cout<<arr[i]<<" ";
    }
}

int Queue :: getData()
{
    if(isEmpty())
        return 0;
    else
    return arr[front];
}
int main()
{
    Queue q; char ch;

    do
    {
        system("cls");
        cout<<"MENU TO PERFORM OPERATIONS ON LINEAR QUEUE (ARRAY IMPLEMENTATION)";
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
