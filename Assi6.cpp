#include<iostream>
using namespace std;

class Node
{
    public:
    int coef;
    int pow;
    Node *next;
    public:
    Node()
    {
        coef=pow=0;
        next=NULL;
    }
};

class LL
{
    public:
    Node *head = NULL;
    
    void create_node(int x, int y)
    {
        Node *nn = new Node();
        nn->coef = x;
        nn->pow = y;
        if(head == NULL)
        {
            head = nn;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    void printpoly()
    {
        if(head !=NULL)
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                cout<<temp->coef<<"x"<<temp->pow<<"+";
                temp = temp->next;
            }
            cout<<temp->coef<<"x"<<temp->pow;
        }
    }

    void polyadd( LL l1, LL l2)
    {
        Node *p1 = l1.head;
        Node *p2 = l2.head;
        Node *result = new Node();
        Node *curr = result;

        while(p1->next != NULL && p2->next != NULL)
        {
            Node *nn = new Node();
            if(p1->pow > p2->pow)
            {
                nn->pow = p1->pow;
                nn->coef = p1->coef;
                p1 = p1->next;
            }
            else if(p1->pow < p2->pow)
            {
                nn->pow = p2->pow;
                nn->coef = p2->coef;
                p2 = p2->next;
            }
            else
            {
                nn->pow = p1->pow;
                nn->coef = p1->coef + p2->coef;
                p1 = p1->next;
                p2=p2->next;
            }
            curr->next = nn;
            curr = curr->next;
        }
        while(p1!= NULL && p2!=NULL)
        {
            if(p1->pow > p2->pow)
            {
                curr->next = p1;
                curr = curr->next;
                p1 = p1->next;
            }
            else if(p1->pow < p2->pow)
            {
                curr->next = p2;
                curr = curr->next;
                p2 = p2->next;
            }
        }
        while(p1 != NULL)
        {
            curr->next = p1;
            curr = curr->next;
            p1 = p1->next;
        }
        while(p2 != NULL)
        {
            curr->next = p2;
            curr = curr->next;
            p2 = p2->next;
        }
        head= result->next;
    }
};

int main()
{
    LL l1,l2,l3;
    l1.create_node(41,7);
    l1.create_node(12,5);
    l1.create_node(65,0);
    l2.create_node(21,5);
    l2.create_node(15,2);
    printf("Polynomial 1: ");
    l1.printpoly();
    printf("\nPolynomial 2: ");
    l2.printpoly();
    l3.polyadd(l1, l2);
    printf("\nPolynomial after adding p1 and p2 : ");
    l3.printpoly();
    return 0;
}