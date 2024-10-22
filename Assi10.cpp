#include<iostream>
using namespace std;

class Node 
{
    public:
    int priority;
    string name;
    Node* next;
    Node* prev;

    Node() {
        name = "";
        priority = -1;
        next = NULL;
        prev = NULL;
    }

    Node(string a, int b) {
        name = a;
        priority = b;
        next = NULL;
        prev = NULL;
    }
};

class jobScheduling 
{
    Node* f = NULL; 
    Node* r = NULL;
    Node* head = NULL; 

    public:
    void addJob(string name, int priority) 
    {
        Node* nn = new Node(name, priority);
        if(head == NULL) 
        {
            head = f = r = nn;
            nn->next = head;
            nn->prev = head;
        }
        else if(nn->priority > f->priority) 
        {
            nn->next = f;
            f->prev = nn;
            f = head = nn;
            f->prev = r;
            r->next = f;
        }
        else if(nn->priority <= r->priority) 
        {
            r->next = nn;
            nn->prev = r;
            r = nn;
            r->next = f;
            f->prev = r;
        }
        else 
        {
            Node* temp = head;
            while(temp->priority > nn->priority && temp != r) 
            {
                temp = temp->next;
            }
            temp->prev->next = nn;
            nn->prev = temp->prev;
            nn->next = temp;
            temp->prev = nn;
        }
    }

    void removeJob() 
    {
        if(head == NULL) 
        {
            cout << "No Job to Remove!" << endl;
            return;
        }

        if(f == r) 
        {
            delete f;
            head = f = r = NULL;
        }
        else
        {
            Node* temp = r;
            r = r->prev;
            r->next = f;
            f->prev = r;
            delete temp;
        }

        cout << "Job with the highest priority removed!" << endl;
    }

    void searchJob(string find) 
    {
        if(head == NULL) 
        {
            cout << "No Job Found" << endl;
            return;
        }

        Node* temp = head;
        if(temp->name == find) 
        {
            cout<<"Job Found."<<endl;
            cout << "Name: " << temp->name << endl << "Priority: " << temp->priority << endl;
            return;
        }

        temp = temp->next;
        while(temp != head) 
        {
            if(temp->name == find) 
            {
                cout<<"Job Found."<<endl;
                cout << "Name: " << temp->name << endl << "Priority: " << temp->priority << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "No Job Found" << endl;
    }

    void displayJob() 
    {
        if(head == NULL) 
        {
            cout << "No Job Found!" << endl;
            return;
        }

        Node* temp = head;
        do 
        {
            cout << "Name: " << temp->name << "   " << "Priority: " << temp->priority << endl;
            temp = temp->next;
        } while(temp != head);
    }
};

int main() 
{
    jobScheduling j;
    string Name, find;
    int priority;
    bool choice = true;
    int ch;
    do 
    {
        cout << "1. Add job\n2. Remove Job\n3. Display Jobs\n4. Search Job\n5. Exit\nEnter Choice: ";
        cin >> ch;

        switch(ch) 
        {
            case 1:
                cout << endl << "Enter Name: ";
                cin >> Name;
                cout << "Enter Priority: ";
                cin >> priority;
                j.addJob(Name, priority);
                break;

            case 2:
                j.removeJob();
                break;

            case 3:
                j.displayJob();
                break;

            case 4:
                cout << "Enter Job to Search: ";
                cin >> find;
                j.searchJob(find);
                break;

            case 5:
                choice = false;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        cout << endl;
    } while(choice);

    return 0;
}
