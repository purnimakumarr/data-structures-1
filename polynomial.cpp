#include<iostream>
#include<stdlib.h>

using namespace std;

template <class X>
class node
{
public:
    int data, power;
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
    void display();
    list add(list, list);
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
    //creating new node
    cout<<"Enter data : ";
    temp=new node<X>;
    cin>>temp->data;
    cout<<"Enter power : ";
    cin>>temp->power;
    temp->next=NULL;

    //for first node
    if(first==NULL)
    {
        first=last=temp;
    }

    else
    {
        if(temp->power>first->power)
        {
            temp->next=first;
            first=temp;
        }

        else if(temp->power<last->power)
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
                if(temp->power<temp1->power && temp->power>temp2->power)
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
list<X> list<X>:: add(list<X> p1, list<X> p2)
{
    temp=p1.first;
    while(temp!=NULL)
    {
        temp1=p2.first;
        while(temp1!=NULL)
        {
            if(temp->power>temp1->power)
            {
                temp2=new node<X>;
                temp2->next=NULL;
                temp2->data=temp->data;
                temp2->power=temp->power;
                break;
            }

            else if(temp->power<temp1->power)
            {
                temp1=temp1->next;
            }

            else if (temp->power==temp1->power)
            {
                temp2=new node<X>;
                temp2->next=NULL;
                temp2->data=temp->data+temp1->data;
                temp2->power=temp->power;
                break;
            }
        }
        if(first==NULL)
            first=last=temp2;
        else
        {
            last->next=temp2;
            last=temp2;
        }
        temp=temp->next;
    }
    return *this;
}

template <class X>
void list<X> :: display()
{
    temp=first;
    //check if list is empty
    if(first==NULL)
        cout<<"List is empty.";

    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"x^"<<temp->power;
            if(temp==last)
                break;
            else
                cout<<" +";
            temp=temp->next;
        }
        cout<<"\n";
    }
}

int main()
{
    list<int> obj1, obj2, obj3; char ch;

    do
    {
        system("cls");
        cout<<"PRAGORAM TO ADD TWO POLYNOMIALS USING LINKED LIST.\n";
        cout<<"1. Insertion.\n";
        cout<<"2. Addition.\n";
        cout<<"3. Display.\n";
        cout<<"Input choice : ";
        cin>>ch;
        switch(ch)
        {
           case '1' :   cout<<"Enter polynomial 1 :-\n";
                        do
                        {
                            obj1.insertion();
                            cout<<"Do you want to add another term(press y/n) : " ;
                            cin>>ch;
                        }while(ch=='y' || ch=='Y');

                        cout<<"Enter polynomial 2 :-\n";
                        do
                        {
                            obj2.insertion();
                            cout<<"Do you want to add another term(press y/n) : ";
                            cin>>ch;
                        }while(ch=='y' || ch=='Y');
                        break;

            case '2' :  obj3.add(obj1, obj2);
                        cout<<"Polynomial after addition: ";
                        obj3.display();
                        break;

            case '3' :  cout<<"Polynomial 1 : ";
                        obj1.display();
                        cout<<"Polynomial 2 : ";
                        obj2.display();
                        break;

            default :   cout<<"Invalid input.\n";
            }
    cout<<"\n Do you want to continue(press y/n) : ";
    cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}
