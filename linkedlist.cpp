#include<iostream>

using namespace std;

class student {
    struct stud {
        int roll_no;
        stud *next;
    } *first=NULL, *last, *head;

public:
    void insertlist();
    void display();
};

void student :: insertlist() {
    head=new stud;
    cin>>head->roll_no;

    if(first==NULL)
        first=last=head;
    else {
        last->next=head;
        last=head;
    }
}

void student :: display() {
    head=first;

    if(first==NULL)
        cout<<"List is empty";

    else {
        while(head!=NULL) {
            cout<<head->roll_no<<" ";
            head=head->next;
        }
    }
}

int main()
{
   student obj; char ch;
   do {
        cout<<"1. Insert\n";
        cout<<"2. Display\n";
        cout<<"Enter choice : ";
        cin>>ch;

        switch(ch) {
            case '1' : cout<<"Input list item : ";
                       obj.insertlist();
                       break;

            case '2' : cout<<"Linked list is : ";
                       obj.display();
                       break;
            default: cout<<"Invalid input";
        }
    cout<<"Do you want to continue: ";
    cin>>ch;
   }while(ch=='y');
   return 0;
}
