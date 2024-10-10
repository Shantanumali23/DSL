#include <iostream>
using namespace std;

int f = -1;
int r = -1;
const int size = 10;
string Q[size];

void Insert(string name) 
{
    if (f == r && r == -1) 
    {
        f = 0;
        r = 0;
        Q[r] = name;
    } 
    else if (r < size - 1) 
    {
        r++;
        Q[r] = name;
    } 
    else 
    {
        cout << "Queue is Overflow." << endl;
        return;
    }
}
void Delete()
{
    if(f>=0 && f<=r)
    {
        string x=Q[f];
        f++;
    }
}

void display()
{
    for(int i=f; i<=r;i++)
    {
        cout<<Q[i]<<" ";
    }
}

int main() 
{
    int choice;
    char ch;
    string name;
    do
    {
        cout<<"\n1.To Add Party to Waitlist. \n2.To Delete Party. \n3.To display Waitlist.\n";
        cout<<"Enter the Choice:";
		cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter the name of Party: ";
                cin>>name;
                Insert(name);
                    break;
            case 2:Delete();
                    break;
            case 3:display();
                    break;
            default : return 0;
        }
        cout<<"\nEnter Y to continue:";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}