#include<iostream>
using namespace std;

class Node
{

int data;
Node  *next;
Node *h1=NULL,*h2=NULL;
public:

void insert(int n1,int n2)
{
   for(int i=1;i<=50;i++)	
   {
   	Node *curr=new Node();
   	curr->data=i*n1;
   	curr->next=NULL;
   	if(h1==NULL)
   	  h1=curr;
   	else
   	{
   		Node *t1=h1;
   		while(t1->next!=NULL)
   		  t1=t1->next;
   		t1->next=curr;
	   }
   }
   for(int i=1;i<=50;i++)	
   {
   	Node *curr=new Node();
   	curr->data=i*n2;
   	curr->next=NULL;
   	if(h2==NULL)
   	  h2=curr;
   	else
   	{
   		Node *t2=h2;
   		while(t2->next!=NULL)
   		  t2=t2->next;
   		t2->next=curr;
	   }
   }
}
void display()
{
	Node *t1=h1;
   	while(t1->next!=NULL)
   	{
   		cout<<t1->data<<"->";
	    t1=t1->next;
    }
    cout<<"\n";
    Node *t2=h2;
    while(t2->next!=NULL)
   	{
   		cout<<t2->data<<"->";
	    t2=t2->next;
    }
}
void findLCM()
{
	Node *t1=h1;
	while(t1->next!=NULL)
	{
	   Node *t2=h2;
	   while (t2->next!=NULL)	
	   {
	   	  if(t1->data==t2->data)
	   	  {
	   	  	cout<<"\n LCM is"<<t1->data;
	   	  	return;
		  }
		  else
		    t2=t2->next;
		    
	  }
	  t1=t1->next;
	}
	
}
};
int main()
{
	Node obj;
	int n1,n2;
	cin>>n1>>n2;
	obj.insert(n1,n2);
	obj.display();
	obj.findLCM();
	
}