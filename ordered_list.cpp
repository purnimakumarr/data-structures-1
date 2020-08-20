#include<iostream>
#include<stdlib.h>

using namespace std;

template <class X>
class node
{
public:
    int data;
    node<X> *next;
};

template <class X>
class list
{
    node<X> *first, *last, *temp, *temp1, *temp2;
public:
    list();
    ~list();
    void insertion();
    void deletion();
    void display();
    list operator+(list &);
};

//constructor
template <class X>
list<X> :: list()
{
    first=NULL;
    last=NULL;
}

//destructor
template <class X>
list<X> :: ~list()
{
    node<X> *p;
    for(; first!=NULL; )
    {
        p=first->next;
        delete first;
        first=p;
    }
    delete p;
}

template <class X>
void list<X> :: insertion()
{
    cout<<"Enter data : ";
    //creating new node
    temp=new node<X>;
    cin>>temp->data;
    temp->next=NULL;

    //for first node
    if(first==NULL)
    {
        first=last=temp;
    }

    else
    {
        if(temp->data<first->data)
        {
            temp->next=first;
            first=temp;
        }

        else if(temp->data>last->data)
        {
            last->next=temp;
            temp->next=NULL;
            last=temp;
        }

        else
        {
            temp1=first;
            temp2=first->next;
            while(temp1!=last)
            {
                if(temp->data>temp1->data && temp->data<temp2->data)
                {
                    temp1->next=temp;
                    temp->next=temp2;
                }
                temp1=temp2;
                temp2=temp2->next;
            }
        }
    }
}

template <class X>
void list<X> :: deletion()
{

    temp=first;

    //check if list is empty
    if(first==NULL)
        cout<<"List is empty. Underflow.";

    //list contains only one node
    else if(first==last)
    {
        delete temp;
        first=NULL;
        last=NULL;
    }

    //deleting node from end of the list
    else
    {
        temp1=last;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        delete temp1;
        last=temp;
        last->next=NULL;
    }
}

template <class X>
void list<X> :: display()
{
    temp=first;
    //check if list is empty
    if(first==NULL)
        cout<<"List is empty";

    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

template <class X>
list<X> list<X> :: operator+(list<X> &obj)
{
    last->next=obj.last;
    last=obj.last;
    return *this;
}

int main()
{
    list<int> obj, obj1, obj2; int ch; char ch1;
    do
    {
        system("cls");
        cout<<"MENU TO PERFORM OPERATIONS ON AN ORDERED LINKED LIST.\n";
        cout<<"1. Insertion.\n";
        cout<<"2. Deletion.\n";
        cout<<"3. Merging.\n";
        cout<<"4. Display.\n";
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1 : obj.insertion();
                       break;

            case 2 : obj.deletion();
                     cout<<"List after deletion : ";
                     obj.display();
                     break;

            case 3 : cout<<"Insert Linked List 1 : ";
                      do
                      {
                          obj1.insertion();
                          cout<<"Do you want to add another node : ";
                          cin>>ch1;
                      }while(ch1=='y');

                      cout<<"Insert Linked List 2 : ";
                      do
                      {
                          obj1.insertion();
                          cout<<"Do you want to add another node : ";
                          cin>>ch1;
                      }while(ch1=='y');

                      obj1=obj1+obj2;
                      cout<<"Linked list after merging  : ";
                      obj1.display();
                      break;

            case 4 : cout<<"Linked List is : ";
                     obj.display();
                     break;

            default : cout<<"\nInvalid Input.";
        }
        cout<<"\nDo you want to continue : ";
        cin>>ch1;
    }while(ch1=='y' ||  ch1=='Y');
    return 0;
}
