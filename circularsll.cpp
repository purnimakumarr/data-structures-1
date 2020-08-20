#include<iostream>
#include<stdlib.h>

using namespace std;

template <class X>
class node
{
public :
    int data;
    node<X> *next;
};
template <class X>
class list
{
    node<X> *tail, *temp, *temp1, *flag;

public:
    list();
    ~list();
    void insert_at_beg();
    void insert_in_mid(int);
    void insert_at_end();
    void delete_from_beg();
    void delete_from_mid(int);
    void delete_from_end();
    void search_item(int);
    void count_item();
    void reverse_list();
    void display();
};

//constructor
template <class X>
list<X> :: list()
{
    tail=NULL;
}

//destructor
template <class X>
list<X> :: ~list()
{
    node<X> *p, *p1=tail;
    for( ; p!=p1; )
    {
        p=tail->next;
        delete tail;
        tail=p;
    }
    delete p;
    delete p1;
}

template <class X>
void list<X> :: insert_at_beg()
{
    //create new node
    temp=new node<X>;
    cin>>temp->data;


    // for first node
    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
    }

    //for all other nodes
    else
    {
        temp->next=tail->next;
        tail->next=temp;
    }

}

template <class X>
void list<X> :: insert_at_end()
{
    //create new node
    temp=new node<X>;
    cin>>temp->data;

    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
    }


    //insert node at end
    else
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }

}

template <class X>
void list<X> :: insert_in_mid(int pos)
{
    int count=1;

    //create new node
    temp1=new node<X>;
    cin>>temp1->data;
    temp1->next=NULL;

    if(tail==NULL)
    {
        tail=temp;
        tail->next=tail;
    }

    //temp traverses to the node after which the user want to inert new node<X>
    else
    {
        temp=tail->next;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }

        //inserting new node
        temp1->next=temp->next;
        temp->next=temp1;
    }

}

template <class X>
void list<X> :: delete_from_beg()
{
    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty. Underflow.";

    //list contains only one node
    else if(tail=tail->next)
    {
        cout<<"Deleting node with data : "<<tail->data;
        temp=tail;
        delete temp;
        tail=NULL;
    }

    //deleting node from the beginning
    else
    {
        temp=tail->next;
        cout<<"Deleting node with data : "<<temp->data;
        tail->next=temp->next;
        delete temp;
    }
}

template <class X>
void list<X> :: delete_from_mid(int pos)
{
    int count=1;
    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty. Underflow.";

    //deleting node from the middle
    else
    {
        temp=tail->next;
        while(count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        temp1=temp->next;
        cout<<"Deleting node with data : "<<temp1->data;
        temp->next=(temp->next)->next;
        delete temp1;
    }
}

template <class X>
void list<X> :: delete_from_end()
{

    temp=tail->next;

    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty. Underflow.";

    //list contains only one node
    else if(tail==tail->next)
    {
        cout<<"Deleting node with data : "<<tail->data;
        delete temp;
        tail=NULL;
    }

    //deleting node from end of the list
    else
    {
        cout<<"Deleting node with data : "<<tail->next;
        temp=tail->next;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=tail->next;
        delete tail;
        tail=temp;
    }
}

template <class X>
void list<X> :: count_item()
{
    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty. Underflow.";

    else
    {
        int counter=0;
        temp=tail->next;

        do
        {
            counter++;
            temp=temp->next;
        }while(temp!=tail->next);
        cout<<"No. of list items : "<<counter;
    }
}

template <class X>
void list<X> :: search_item(int search)
{
    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty. Underflow.";

    else
    {
        temp=tail->next; int counter=0, pos=0;
        do
        {
            pos++;
            if(temp->data==search)
            {
                counter=1;
                cout<<"Item found at position : "<<pos;
                break;
            }
            temp=temp->next;
        }while(temp!=tail->next);
        if(counter==0)
            cout<<"Item not found in the list.";
    }
}

template <class X>
void list<X> :: display()
{
    temp=tail->next;
    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty";

    else
    {
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=tail->next);
    }
}

template <class X>
void list<X> :: reverse_list()
{
    //check if list is empty
    if(tail==NULL)
        cout<<"List is empty. Underflow.";

    else
    {
        temp=tail->next;
        temp1=temp->next;

        while(temp!=tail)
        {
            flag=temp1->next;
            temp1->next=temp;
            temp=temp1;
            temp1=flag;
        }
        temp1->next=tail;
        tail=temp1;
    }
}

int main()
{
   list<int> obj; int ch; char ch1; int pos,search;
   do
    {
        system("cls");
        cout<<"MENU TO PERFORM ACTIONS ON A CIRCULAR SINGLY LINKED LIST USING TEMPLATES\n";
        cout<<"1. Insert at beginning.\n";
        cout<<"2. Insert in middle.\n";
        cout<<"3. Insert at end.\n";
        cout<<"4. Delete from beginning.\n";
        cout<<"5. Delete from middle.\n";
        cout<<"6. Delete from end.\n";
        cout<<"7. Search in the linked list.\n";
        cout<<"8. Count the no of items in the list.\n";
        cout<<"9. Reverse the linked list.\n";
        cout<<"10. Display the linked list.\n";
        cout<<"Enter choice : ";
        cin>>ch;

        switch(ch) {
            case 1 : cout<<"Input list item : ";
                       obj.insert_at_beg();
                       break;

            case 2 : cout<<"Input the position at which you want to add data : ";
                     cin>>pos;
                     cout<<"Input List Item : ";
                     obj.insert_in_mid(pos);
                     break;

            case 3 : cout<<"Input List Item : ";
                       obj.insert_at_end();
                       break;

            case 4 : obj.delete_from_beg();
                       cout<<"\nList after deletion is : ";
                       obj.display();
                       break;

            case 5 : cout<<"Enter the list item no. you want to delete : ";
                       cin>>pos;
                       obj.delete_from_mid(pos);
                       cout<<"\nList after deletion : ";
                       obj.display();
                       break;

            case 6 : obj.delete_from_end();
                       cout<<"\nList after deletion : ";
                       obj.display();
                       break;

            case 7 : cout<<"Enter the item data you want to search : ";
                       cin>>search;
                       obj.search_item(search);
                       break;

            case 8 : obj.count_item();
                       break;

            case 9 : obj.reverse_list();
                     cout<<"List after reversing : ";
                     obj.display();
                     break;

            case 10 : cout<<"Linked List : ";
                        obj.display();
                        break;

            default   : cout<<"Invalid input";
        }
    cout<<"\nDo you want to continue: ";
    cin>>ch1;
   }while(ch1=='y');
   return 0;
}

