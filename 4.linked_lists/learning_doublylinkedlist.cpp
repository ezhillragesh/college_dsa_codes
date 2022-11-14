#include<iostream>
using namespace std;
class node
{
	node *prev;
	int data;
	node *succ;
	public:
	node *head=NULL;
	void insertbeg(int val)
	{
	    node *nn=new node();
	    nn->data=val;
	    nn->succ=NULL; 	
	    nn->prev=NULL;
	    if(head==NULL)
	    {
	  	  head=nn;
	  	 
	  	  return;
        }
    else
    {   
        nn->succ=head;
        head->prev=nn;
        head=nn;
	}
   }
  void insertend(int val)
   {
   	node *nn=new node();
	nn->data=val;
	nn->succ=NULL;
	nn->prev=NULL;
	if(head==NULL)
	{
	  	  head=nn;
	  	  return;
    }
    node *temp=head;
    while(temp->succ!=NULL)
    { temp=temp->succ;
	}
	
	temp->succ=nn;
	nn->prev=temp;
	
   }
   void deletebeg()
   {
   	  node *temp;
   	if(head==NULL)
   	{cout<<" the list is empty. u can't delete";
   	 return;
	 }
   	temp=head;
   	head=head->succ;
   	head->prev=NULL;
   	cout<<"the deleted item is "<<temp->data;
   	delete(temp);
   }
   void deleteend()
   {
   	node  *temp=head;
   	while(temp->succ!=NULL)
   	   	  temp=temp->succ;
   (temp->prev)->succ=NULL;
   cout<<"the deleted item is "<<temp->data;
   delete(temp);
   }
   
   void display()
   {
   	node *temp=head;
   	while(temp!=NULL)
   	{
   		cout<<temp->data<<" ";
   		temp=temp->succ;
	   }
   }
   void insertmiddle(int val)
   {int n;
   	node *nn=new node();
	nn->data=val;
	nn->succ=NULL;
	nn->prev=NULL;
	if(head==NULL)
	{
	  	  head=nn;
	  	  return;
    }
    cout<<"enter the number of nodes after which you want to insert this";
    cin >>n;
    node *temp=head;
    int count=1;
    while(count<n && temp->succ!=NULL)
    {
      temp=temp->succ;
      count++;
	}
	nn->succ=temp->succ;
	(temp->succ)->prev=nn;
	temp->succ=nn;
	nn->prev=temp;
   }
   void deletemiddle()
   {int delval;
   	 node *temp=head;
   	 cout<<"enter the node value that u want to delete";
   	 cin>>delval;
   	 while(temp->data!=delval&&temp->succ!=NULL)
   	 	temp=temp->succ;
	 if(temp->data!=delval)
	{cout<<"there is no such node in the list";
	  return;
	}
	 (temp->prev)->succ=temp->succ;
	 (temp->succ)->prev=temp->prev;
	 cout<<"deleted item is "<<temp->data;
	 delete(temp);
   }
};
int main()
{
	int choice,val;
	node obj;
	do
	{
	
	cout<<"enter ur choice 1-insert in the beg 2-insert at the end .......";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"enter the value u want to insert";
		        cin>>val;
		        obj.insertbeg(val);
		        break;
	    case 2: cout<<"enter the value u want to insert";
		        cin>>val;
		        obj.insertend(val);
		        break;
		case 3: cout<<"enter the value u want to insert";
		        cin>>val;
		        obj.insertmiddle(val);
		        break;
	    	    
	    case 4:obj.deletebeg();
	           break;
	    case 5:obj.deleteend();
	           break;
	    case 6: obj.deletemiddle();
	            break;
	    case 7: obj.display();
	            break;
	    
	}
  }while(choice!=8);
}