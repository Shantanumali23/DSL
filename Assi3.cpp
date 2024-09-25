#include<iostream>
using namespace std;

class song
{
    public:
    float duration;
    song *next;
    song()
    {
        duration=0;
        next=NULL;
    }
    song(float d)
    {
        duration=d;
        next=NULL;
    }
};

class playlist
{
    song *head;
    public:
    playlist()
    {
        head=0;
    }
    void insert_start(float d)
    {
        song *nn=new song(d);
        if(head ==NULL)
        {
            cout<<"List is Empty.";
            head=nn;
            return;
        }
        else
        {
            nn->next = head;
            head=nn;
        }
    }
    void insert_end(float d)
    {
        song *nn =new song(d);
        if(head==NULL)
        {
            head=nn;
            return;
        }
        else
        {
            song *temp=new song();
            temp=head;
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next = nn;
        }
    }
    void print()
    {
        cout<<"Displaying LL:";
        song *temp = new song();
        temp=head;
        while(temp->next != NULL)
        {
            cout<<temp->duration<<" ";
            temp=temp->next;
        }
        cout<<temp->duration;
    }
    void insert_between(float d, float key)
    {
        song *nn=new song(d);
        if(head==NULL)
        {
            head=nn;
            return;
        }
        else{
            song *temp=new song();
            temp=head;
            while(temp->next != NULL)
            {
                if(temp->duration == key)
                {
                    nn->next = temp->next;
                    temp->next =nn;
                }
                temp=temp->next;
            }
        }
    }

    void delete_start(float d)
    {
        if(head->next != NULL)
        {
            head=head->next;
        }
    }

    void delete_end(float d)
    {
        if(head == NULL)
        {
            cout<<"Linked List is Empty.";
        }
        else{
            song *temp = new song();
            song *temp1 = new song();
            temp = head;
            while(temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = NULL;
        }
    }

    void delete_bet(float d,float key)
    {
        if(head == NULL)
        {
            cout<<"Linked List is Empty.";
        }
        else
        {
            song *temp = new song();
            song *temp1 = new song();
            temp = head;
            while(temp->duration != key)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
        }
    }

    void search(float d)
    {
        
    }
};
int main()
{
    int choice; float m,key;
    char ch;
    playlist p;
    do
    {
        cout<<"\n1.To Insert song at Start. \n2.To Insert song at End. \n3.To Insert song in Between. \n4.To print Songs. \n5.To delete song at Start. \n6.To delete song at end. \n7.To delete song in Between.\n";
        cout<<"Enter the Choice:";
		cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter duration of song:";
                cin>>m;
                p.insert_start(m);
                    break;
            case 2 :cout<<"Enter duration of song:";
                cin>>m;
                p.insert_end(m);
                    break;
            case 3: cout<<"Enter the duration of song to add after:";
                cin>>key;
                cout<<"Enter duration of song:";
                cin>>m;
                p.insert_between(m,key);
                    break;
            case 4: p.print();
                    break;
            case 5: p.delete_start(m);
                    p.print();
                    break;
            case 6: p.delete_end(m);
                    p.print();
                    break;
            case 7: cout<<"Enter the duration of song to delete after:";
                cin>>key;
                cout<<"Enter duration of song:";
                cin>>m;
                p.delete_bet(m,key);
                p.print();
                    break;
            default : return 0;
        }
        cout<<"\nEnter Y to continue:";
        cin>>ch;
    }while(ch=='y');
    return 0;
}