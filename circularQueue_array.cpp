#include<iostream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define size 5

class circularQueue
{
    int arr[size], front, rear;
public:
    circularQueue();
    void enqueue(int data);
    void dequeue();
    void display();
    void clear();
    int getData();
    int isEmpty();
    int isFull();
};

circularQueue :: circularQueue()
{
    front=rear=-1;
}

int circularQueue :: isFull()
{
    if((front==0 && rear==size-1) || front==rear+1)
        return 1;
    else
        return 0;
}

int circularQueue :: isEmpty()
{
    if(rear==-1)
        return 1;
    else
        return 0;
}
void circularQueue :: enqueue(int data)
{
    //if queue is full
    if(isFull())
    {
        cout<<"Overflow.";
        exit(0);
    }
    //for first node
    else
        if(isEmpty())
            {
                front++;
                arr[++rear]=data;
            }
    //if there is empty space for node in the beginning
    else
        if(rear==size-1 && front>0 )
        {
            rear=0;
            arr[rear]=data;
        }
    //for every other node
    else
        arr[++rear]=data;
}

void circularQueue :: dequeue()
{
    //if queue is empty
    if(isEmpty())
        cout<<"Underflow.";
    //if queue contains single node
    else
        if(front==rear)
    {
        cout<<"\nDeleted Item : "<<arr[front];
        front=rear=-1;
    }
    //if front is pointing the last index no. but there are other nodes in the queue
    else
        if(front==size-1)
        {
            cout<<"Deleted Item : "<<arr[front];
            front=0;
        }
    //for every other node
    else
    {
        cout<<"\nDeleted Item : "<<arr[front];
        front++;
    }
}

void circularQueue :: clear()
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

void circularQueue :: display()
{
    ///if queue is empty
    if(isEmpty())
        cout<<"Queue is empty.";
    //print the queue
    else
        if(rear>=front)
        {
            cout<<"Queue : ";
            for(int i=front; i<=rear; i++)
            cout<<arr[i]<<" ";
        }

    else
    {
        cout<<"Queue : ";
        for(int i=front; i<size; i++)
            cout<<arr[i]<<" ";
        for(int i=0; i<=rear; i++)
            cout<<arr[i]<<" ";
    }
}

int circularQueue :: getData()
{
    if(isEmpty())
        return 0;
    else
    return arr[front];
}
int main()
{
    circularQueue q; char ch;

    do
    {
        system("cls");
        cout<<"MENU TO PERFORM OPERATIONS ON CIRCULAR QUEUE (ARRAY IMPLEMENTATION)";
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
