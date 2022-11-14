#include <bits/stdc++.h>
using namespace std;
//21BBS0100
class cnode{
    public:
    int data;
    cnode *next;
    public:
    cnode *head;
    cnode(){
        head=NULL;
        next=NULL;
        
    }
    void insertathead(int val)
    {
        cnode *temp=head;//!temp variable is used to traverse so the head value dont change 
        cnode *cur=new cnode();
        cur->data=val;
        if(head==NULL)
        {
            cur->next=cur;
            head=cur;
            return;
        }
        while (temp->next!=head) temp=temp->next;//!now temp is seconf last cnode
        temp->next=cur;
        cur->next=head;
        head=cur;
    }
        
        

    void insertatend(int val){
        if(head==NULL){//!if the list is empty
            insertathead(val);
            return;
        }

        cnode*temp=head;
        cnode *cur=new cnode();
        cur->data=val;
        while(temp->next!=head) temp=temp->next;
        temp->next=cur;
        cur->next=head;
    }

    void insertanywhere(int val,int pos){
        if(head==NULL || pos==1)
        {
            insertathead(val);
            return;
        }
        cnode *temp=head;
        cnode *cur=new cnode();
        cur->data=val;
        int j=1;
        
        while(j!=pos-1){
            temp=temp->next;
            j++;
        }
        
        cur->next=(temp->next);
        temp->next=cur;

    }     
    void deleteAtHead(){
    cnode* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    cnode* todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
    }
    void deletion( int pos){

    if(pos==1){
        deleteAtHead();
        return;
    }
      cnode* temp=head;
      int count=1;

      while(count!=pos-1){
          temp=temp->next;
          count++;
      }

      cnode* todelete=temp->next;
      temp->next=temp->next->next;

      delete (todelete);
}

void display(){
        cnode *temp=head;
        do{//?can not use while loop with(temp->next=head) because at last iteration the condition is true so the last element will not be printed.
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
        
    }


};

int main(){
    cnode list;
    int choice,ch,num,pos;
    do
	{
	
	cout<<"\nEnter the Operation to be performed:\n1.insert\n2.delete\n3.Display\nYour Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"Enter the value you want to insert : ";
		        cin>>num;
		        cout<<"where to insert\n1.Begining\n2.End\n3.Desired Position\nYour Choice: ";
                cin>>ch;
                if(ch==1) list.insertathead(num);
                else if(ch==2) list.insertatend(num);
                else if(ch==3){
                    cout<<"Enter Position : ";
                    cin>>pos;
                    list.insertanywhere(num,pos);
                }
                else cout<<"Invalid Input";

		        break;
	    case 2: cout<<"where to Delete\n1.Begining\n2.Desired Position\nYour Choice: ";
                cin>>ch;
                if(ch==1) list.deleteAtHead();
                else if(ch==2){
                    cout<<"Enter Position : ";
                    cin>>pos;
                    list.deletion(pos);
                }
                else cout<<"Invalid Input";
                break;

		case 3: list.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}
    
