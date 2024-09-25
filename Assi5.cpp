#include<iostream>
using namespace std;

class CLL
{
    public:
    int route;
    CLL *next;
    CLL *previous;
    public:
    CLL()
    {
        route=0;
        next=NULL;
        previous = NULL;
    }
    CLL(int d)
    {
        route=d;
        next=NULL;
        previous = NULL;
    }
};

class Nav
{
    CLL *head;
    public:
    Nav()
    {
        head=0;
    }

    void insert_end(int d)
    {
        CLL *nn = new CLL(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            CLL *temp = new CLL();
            temp = head;
            while(temp->next != head && temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
            head->previous = nn;
            nn->previous = temp;
            nn->next = head;
        }
    }
    void print()
    {
        cout<<"Displaying Route:";
        CLL *temp = new CLL();
        temp=head;
        while(temp->next != head && temp->next != NULL)
        {
            cout<<temp->route<<" ";
            temp=temp->next;
        }
        cout<<temp->route;
    }

    void delete_end(int d)
    {
        if(head == NULL)
        {
            cout<<"List is Empty";
        }
        else
        {
            CLL *temp = new CLL();
            temp = head;
            while(temp->next != NULL && temp->next != head)
            {
                temp = temp->next;
            }
            temp->previous->next = head;
        }
    }

    void insert_start(int d)
    {
        CLL *nn = new CLL(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            CLL *temp = new CLL();
            temp = head;
            while(temp->next != head && temp->next != NULL)
            {
                temp = temp->next;
            }
            head->previous = nn;
            nn->next = head;
            nn->previous = temp;
            temp->next = nn;
            head = nn;
        }
    }

    void delete_end(int d)
    {
        if(head == NULL)
        {
            cout<<"List is Empty";
        }
        else
        {
            
        }
    }
};

int main()
{
    int choice, m,key;
    char ch;
    Nav p;
    do
    {
        cout<<"\n1.To Add Route at Start. \n2.To Add Route at End \n3.To display Route. \n4.To Delete Route.\n";
        cout<<"Enter the Choice:";
		cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the route:";
                cin>>m;
                p.insert_start(m);
                p.print();
                    break;
            case 2:cout<<"Enter the route:";
                cin>>m;
                p.insert_end(m);
                p.print();
                    break;
            case 3:p.print();
                    break;
            case 4:p.delete_end(m);
                p.print();
                    break;
            default : return 0;
        }
        cout<<"\nEnter Y to continue:";
        cin>>ch;
    }while(ch=='y');
    return 0;
}