#include<iostream>
#define max 60
using namespace std;
class node
{
	int data;
	node *next;
	public:
	node *rear=NULL,*front=NULL;
	void enqueue(int val)
	{
	  	node *newnode=new node();
	  	newnode->data=val;
	  	newnode->next=NULL;
	  	if(rear==NULL)
	  	{
		  front=newnode;
		  rear=newnode;
	    }
	  	else
	  	{
	  	  rear->next=newnode;
	  	  rear=newnode;
		  }
 
}
int dequeue()
{
	if(isempty())
	
		cout<<"queue is empty. Can't dequeue....";
	else
	{
	node *temp=front;      
	int x=temp->data;
	front=front->next;
	if(front==NULL)
	  rear=NULL;
	delete(temp);
	return(x);
	
    }
}
void display()
{node *temp=front;
while(temp!=NULL)
{
  cout<<temp->data<<" ";
  temp=temp->next;
}
	
}
int isempty()
{
	if(rear==NULL)
	  return 1;
	else
	  return 0;
}
};

int main()
{
	int choice,val,x;
	node obj;
	do
	{
	
	cout<<"enter ur choice 1-enqueue 2-dequeue 3-display .......";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"enter the value u want to insert";
		        cin>>val;
		        obj.enqueue(val);
		        break;
	    case 2: if(!obj.isempty())
	            {
		        x=obj.dequeue();
		        cout<<"dequeued item is "<<x<<"\n";
		        }
		        else
		          cout<<"queue is empty";
				break;
		case 3: obj.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}