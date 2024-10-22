#include<iostream>
using namespace std;

class Node 
{
    public:
    int  tokenNo;
    Node* next;
    Node() 
    {
        tokenNo = 0;
        next = NULL;
    }
    Node(int x) 
    {
        tokenNo = x;
        next = NULL;
    }
};

class Hotel 
{
    Node* f = NULL; Node* r = NULL;
    int count = 0;
    public:
    void addParty(int x)
    {
        if(r == NULL && f == NULL)
        {
            Node* nn = new Node(x);
            f = r = nn;
            count++;
        }
        else if (count < 5)
        {
            Node* nn = new Node(x);
            r->next = nn;
            r = nn;
            count++;
        }
        else 
        {
            cout << endl << "Party List is Full!" << endl;
        }
    }

    void seatParty()
    {
        if(f != NULL && r != NULL)
        {
            Node* temp = f;
            f = f->next;
            delete temp;
        }
        else 
        {
            r = NULL;
            cout << "Party List is  Empty!";
        }
    }
    
    void displayWaitList()
    {
        cout << endl <<  "Displaying WaitList : " << endl;
        Node* temp = f;
        while(temp != NULL) 
        {
            cout << temp->tokenNo << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Hotel h;
    int tokenNo;
    bool choice = true;
    int ch;
    do{ 
        cout << "\n1.To Add Party to Waitlist. \n2.To Delete Party. \n3.To display Waitlist. \n4.Exit \n";
        cout<<"Enter Choice: ";
        cin >> ch;
        switch(ch){
            case 1 :
            cout << "Enter Token No : ";
            cin >> tokenNo;
            h.addParty(tokenNo);
            break;

            case 2 :
            h.seatParty();
            break;

            case 3 :
            h.displayWaitList();
            break;

            case 4 :
            choice = false;
            break;
        }
        cout << endl;
    }while(choice == true);
    return 0;
}