#include<iostream>
using namespace std;

class History
{
    public:
    int top1, top2;
    string s1[5];
    string s2[5];
    History()
    {
        top1=-1;
        top2 = -1;
    }

    void push(string a)
    {
        if(top1 < 5)
        {
            top1++;
            s1[top1]=a;
        }
    }

    void curr()
    {
        cout<<"Current Page: "<<s1[top1]<<endl;
    }

    void nav_back()
    {
        if(top1 == -1)
        {
            cout<<"No history."<<endl;
        }
        else
        {
            top2++;
            s2[top2] = s1[top1];
            top1--; 
        }
    }

    void show()
    {
        cout<<"Name of the Visited Site is: ";
        for(int i=0;i<=top1;i++)
        {
            cout<<s1[i]<<" "<<endl;
        }
    }

    void empty()
    {
        if(top1 == -1)
        {
            cout<<"History is Empty.";
        }
        else
        {
        cout<<"History is Not Empty.";
        }
    }
};

int main()
{
    int choice; char ch; string name;
    History h;
    do
    {
        cout<<"\n1.To Add Visited Page. \n2.To Navigate Back. \n3.To View Current Page. \n4.To Check if history is empty or not.\n";
        cout<<"Enter the Choice:";
		cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the Site Name: ";
                cin>>name;
                h.push(name);
                h.show();
                    break;
            case 2:h.nav_back();
                h.show();
                    break;
            case 3:h.curr();
                    break;
            case 4:h.empty();
                    break;
            default : return 0;
        }
        cout<<"\nEnter Y to continue:";
        cin>>ch;
    }while(ch=='y');
    return 0;
}