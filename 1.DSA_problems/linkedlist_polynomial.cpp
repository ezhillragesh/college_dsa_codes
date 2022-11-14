#include<iostream>
using namespace std;

class Node
{
	int coeff,degree;
	Node *next;
	public:
		Node *h1=NULL,*h2=NULL,*h3=NULL;
		void createlist()
		{
			int n1,n2; int c,d;
			cout<<"Enter the number of terms in P1:";
			cin>>n1;
			for(int i=0;i<n1;i++)
			{
				cout<<"Enter the coefficient and power of"<<i<<"th term";
				cin>>c>>d;
				Node *curr= new Node();
				curr->coeff=c;
				curr->degree=d;
				curr->next=NULL;
				if(h1==NULL)
				    h1=curr;
				else
				{
					Node *temp=h1;
					while (temp->next!=NULL)
					    temp=temp->next;
					temp->next=curr;
			    }
			    
		    }
		    cout<<"Enter the number of terms in P2:";
			cin>>n2;
			for(int i=0;i<n2;i++)
			{
				cout<<"Enter the coefficient and power of"<<i<<"th term";
				cin>>c>>d;
				Node *curr= new Node();
				curr->coeff=c;
				curr->degree=d;
				curr->next=NULL;
				if(h2==NULL)
				    h2=curr;
				else
				{
					Node *temp=h2;
					while (temp->next!=NULL)
					    temp=temp->next;
					temp->next=curr;
			    }
			    
		        }
		    }
		void display(int x)
		{
			Node *p=NULL;
			switch(x)
		    {
		    	case 1: p=h1;
		    	        break;
		    	case 2:p=h2;
		    	       break;
		    	case 3: 
		    	       p=h3;
		    	       break;
			}
			if(p==NULL)
		        {
			        cout<<"Empty list";
			        return;
		        }
		        Node *temp=p;
		        
		        while(temp!=NULL)
		        {
			        cout<<temp->coeff;
					if(temp->degree!=0)
					  cout<<"x";
			        if(temp->degree!=0)
			            cout<<temp->degree;
			        if(temp->next!=NULL)
			            cout<<"+";
			        temp=temp->next;
			    }
			    cout<<"\n";
			}
		void add()
		{
		
			Node *t1=h1, *t2=h2;
			Node *dummy;
			while(t1!=NULL && t2!=NULL)
			{
				Node *curr=new Node();
				if(t1->degree==t2->degree)
				{
					curr->coeff=t1->coeff+t2->coeff;
					curr->degree=t1->degree;
					curr->next=NULL;
					t1=t1->next;
					t2=t2->next;
				}
				else if(t1->degree>t2->degree)
				{
					curr->coeff=t1->coeff;
					curr->degree=t1->degree;
					t1=t1->next;
				}
				else
				{
					curr->coeff=t2->coeff;
					curr->degree=t2->degree;
					t2=t2->next;
				}
				if(h3==NULL)
				    h3=curr;
				else
				{
					dummy=h3;
					while(dummy->next!=NULL)
					    dummy=dummy->next;
					dummy->next=curr;
				}
			}
			if (t1!=NULL)
			{
				dummy->next=t1;
		    }
		    if(t2!=NULL)
		        dummy->next=t2;
		}
	};
main()
{
	Node obj;
	obj.createlist();
	obj.display(1);
	obj.display(2);
	obj.add();
	obj.display(3);
}