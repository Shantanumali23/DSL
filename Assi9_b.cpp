#include<iostream>
using namespace std;

class Node 
{
public:
    string data;
    Node* next;

    Node() 
    {
        next = NULL;
    }

    Node(string d) 
    {
        data = d;
        next = NULL;
    }
};

class LL 
{
    Node* head;
    public:
    LL() 
    {
        head = NULL;
    }

    void insert(string d) 
    {
        Node* nn = new Node(d);
        if (head == NULL) 
        {
            head = nn;
        } else 
        {
            nn->next = head;
            head = nn;
        }
    }

    void customer_checkout() 
    {
        if (head == NULL) 
        {
            cout << "No Customer Found!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Customer checked out." << endl;
    }

    void CloseCheckoutCounter() 
    {
        while (head != NULL) 
        {
            customer_checkout();
        }
        cout << "Checkout counter closed. All customers checked out." << endl;
    }

    void print() 
    {
        if (head == NULL) 
        {
            cout << "No Customers in the list." << endl;
            return;
        }

        Node* temp = head;
        cout << "Customers in the queue: ";
        while (temp != NULL) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LL l;
    int choice;
    char ch;
    string name;
    do
    {
        cout<<"\n1.To Add Customer Arrival. \n2.To Customer CHeckout. \n3.To Close Checkout Counter. \n4.To View customer\n";
        cout<<"Enter the Choice:";
		cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the name of Customer: ";
                cin>>name;
                l.insert(name);
                l.print();
                    break;
            case 2:l.customer_checkout();
                    break;
            case 3:l.CloseCheckoutCounter();
                    break;
            case 4:l.print();
            default : return 0;
        }
        cout<<"\nEnter Y to continue:";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}