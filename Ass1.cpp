#include<iostream>
using namespace std;
class student
{
	private:
	string name;
	int age,roll_no,n;

	public:
	void input(student s[],int n);
	void display(student s[],int n);
	void insertion_sort(student s[],int n);
	void shell_sort(student s[],int n);
};
void student :: input(student s[],int n)
{
	for(int i=0;i<n;i++)
	{
    	cout<<"Enter your name:";
    	cin>>s[i].name;
    	cout<<"Enter your age:";
    	cin>>s[i].age;
    	cout<<"Enter your roll_no:";
    	cin>>s[i].roll_no;
	}
}
void student :: display(student s[],int n)
{
	cout<<"Sorted List according to Roll_no is:"<<endl;
	for(int i=0;i<n;i++)
	{
    	cout<<"Name:"<<s[i].name<<endl;
    	cout<<"Roll No:"<<s[i].roll_no<<endl;
    	cout<<"Age:"<<s[i].age<<endl;
	}
}
void student :: insertion_sort(student s[],int n)
{
	for(int i=1;i<n;i++)
	{
    	int j=i-1;
    	student val=s[i];
    	while(j>=0 && s[j].roll_no>val.roll_no)
    	{
        	s[j+1]=s[j];
        	j=j-1;
    	}
    	s[j+1]=val;
	}
}

void student :: shell_sort(student a[],int n)
{
	int gap=n/2;
	while(gap>=1)
	{
		for(int j=gap;j<n;j++)
		{
			for(int i=j-gap;i>=0;i=i-gap)
			{
				if(a[i+gap].name > a[i].name)
				{
					break;
				}
				else{
					student temp;
					temp=a[i=gap];
					a[i+gap]=a[i];
					a[i]=temp;
				}
			}
		}
		gap=gap/2;
	}
}

int main()
{
	char ch; int choice;
	int n;
	cout<<"Enter the no of students:";
	cin>>n;
	student s[n],x;
	do{
		cout<<"Enter the Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: x.input(s , n);
			break;
			case 2: x.insertion_sort(s,n);
			break;
			case 3: x.display(s,n);
			break;
			case 4: x.shell_sort(s,n);
					x.display(s,n);
					break;
			default:return 0;
		}
		cout<<"Enter Y to continue:";
		cin>>ch;
	} while(ch=='Y');
	return 0;
}
