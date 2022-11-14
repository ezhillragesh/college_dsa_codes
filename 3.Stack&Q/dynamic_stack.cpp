#include<iostream>
using namespace std;
//21BBS0100
class node
{
	int data;
	node *next;
	public:
	node *top=NULL;
	void push(int val)
	{
	  	node *current=new node();
	  	current->data=val;
	  	current->next=NULL;
	  	if(top==NULL) 
	  	  top=current;
	  	else
	  	{
	  	  current->next=top;
	  	  top=current;
		  }
 
}
int pop()
{
	if(isempty())
	
		cout<<"Stack is empty Can't pop *UNDERFLOW*";
	else
	{
	node *temp=top;      
	int x=temp->data;
	top=top->next;
	delete(temp);
	return(x);
    }
}

void display()
{node *temp=top;
while(temp!=NULL)
{
  cout<<temp->data<<" ";
  temp=temp->next;
}
	
}
bool isempty()
{
	if(top==NULL)
	  return true;
	else
	  return false;
}
};
int main(){
    node obj;
    int popped;
    int num,choice;
    do
	{
	
	cout<<"\nEnter the Operation to be performed:\n1.Push\n2.Pop\n3.Display\nYour Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"Enter the value you want to insert : ";
		        cin>>num;
		        obj.push(num);
		        break;
	    case 2: if(!obj.isempty())
	            {
		        popped=obj.pop();
		        cout<<" Popped Item is "<<popped<<"\n";
		        }
		        else
		          cout<<"Stack is Empty";
				break;
		case 3: obj.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}