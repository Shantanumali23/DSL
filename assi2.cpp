#include<iostream>
using namespace std;

class employee
{
    public:
    int emp_id;
    string name;
    int emp_salary;
    void input(employee e[],int n);
    void display(employee e[],int n);
    void qs(employee e[],int F,int L);
    void merge_sort(employee e[],int l,int r);
    void merge(employee e[],int l,int m,int r);
};

void employee:: input(employee e[],int n)
{
    for(int i=0;i<n;i++)
    {
    cout<<"Enter the name of Employee:";
    cin>>e[i].name;
    cout<<"Enter the Employee id:";
    cin>>e[i].emp_id;
    cout<<"Enter the employee Salary:";
    cin>>e[i].emp_salary;
    }
}

void employee :: display(employee e[],int n)
{
    for(int i=0;i<n;i++)
    {
    cout<<"Name:"<<e[i].name<<endl;
    cout<<"Empoloyee id:"<<e[i].emp_id<<endl;
    cout<<"Employee salary:"<<e[i].emp_salary<<endl;
    }
}

void employee::qs(employee e[], int F,int L)
{
    if(F<L)
    {
        int pivot =F;
        int i=F+1;
        int j=L;
        while(i<j)
        {
            while(e[i].emp_id<e[pivot].emp_id)
                i++;
            while(e[j].emp_id>e[pivot].emp_id)
                j--;
            if(i<j)
            {
                employee t;
                t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
            else
                break;
        }
        employee temp;
        temp=e[j];
        e[j]=e[pivot];
        e[pivot]=temp;
        qs(e,F,j-1);
        qs(e,j+1,L);
    }
}

void employee:: merge_sort(employee e[],int l,int r)
{
    if(l>=r)
        return;
    else
    {
        int mid=(l+r)/2;
        merge_sort(e,l,mid);
        merge_sort(e,mid+1,r);
        merge(e,l,mid,r);
    }
}
void employee:: merge(employee e[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;

    employee L[n1]; employee R[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]= e[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]= e[m+1+j];
    }

    int x=0; int y=0; int k=l;
    while(x<n1 &&y<n2)
    {
        if(L[x].name<=R[y].name)
        {
            e[k]=L[x];
            x++;
        }
        else
        {
            e[k]=R[y];
            y++;
        }
        k++;
    }
    while(x<n1)
    {
        e[k]=L[x];
        x++;
        k++;
    }
    while(y<n2)
    {
        e[k]=R[y];
        y++;
        k++;
    }
}
int main()
{
    int n; char ch; int choice;
    cout<<"Enter the no of Employees:";
    cin>>n;
    cout<<"\n1.Add Employee \n2.Sort According to Emp_id \n3.Sort According to Employee Name \n4.Exit \n";
    employee e[15],x;
    int F=0; int L=n-1;
    int l=0;int r=n-1;
    do{
		cout<<"Enter the Choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: x.input(e , n);
			break;
			case 2: x.qs(e,F,L);
                    x.display(e,n);
			break;
            case 3: x.merge_sort(e,l,r);
                    x.display(e,n);
            break;
        default:return 0;
        }
		cout<<"Enter Y to continue:";
		cin>>ch;
	    } while(ch=='Y');
    return 0;
}