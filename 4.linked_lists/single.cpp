#include <iostream>
using namespace std;

//Singly Linked List 

class node{
    int data;
    node*next;
    public:
        node*head;
        void init(){
            head=NULL;
        }

        void insert_begining(int d){
            node*current=new node();
            current->data=d;
            current->next=NULL;
            if(head==NULL){//if the list is empty
                head=current;
            }
            else{
                current->next=head;
                head=current;

            }
        }
        void insert_end(int d){
            node*current=new node();
            current->data=d;
            current->next=NULL;
            node*temp=head;
            while(temp->next!=NULL){//to traverse to the last of the list
                temp=temp->next;
            }
            temp->next=current;//linking the the newly inserted code with last node
        }

        void insert_between(int d,int p){//d is the data....p after how many nodes
            node*current=new node();
            current->data=d;
            current->next=NULL;
            int j=1;
            node*temp=head;
            while(j<p-1){//to traverse to the given position p
                temp=temp->next;
                j++;
            }
            current->next=temp->next;//need to understand
            temp->next=current;

        }
        void display(){
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
        int begining_delete(){//To delete a node from begining of the list
            if(head==NULL){
                cout<<"Empty List ";
        
            }
            else{
                int x=head->data;
                node *temp=head;
                head=head->next;
                delete(temp);
                return x;

            }
        }

        int end_delete(){//To delete a node from the end of the list
            if(head==NULL){
                cout<<"Empty List ";
            }
            else{
                node*temp=head;
                node*prev=NULL;
                while(temp->next!=NULL){
                    prev=temp;
                    temp=temp->next;
                }
                prev->next=NULL;
                int x=temp->data;
                delete(temp);
                return x;

                
            }
        }
            int between_delete(int pos){//pos gives the node to delete to...
                if(head==NULL)
                    cout<<"Empty list yo";
                else{
                    node*temp=head;
                    
                     for(int j=0;j<pos-1;j++){
                        temp=temp->next;
                        temp->next=(temp->next)->next;
                    }
                }
            }
    
            
            

            
            
        

};
int main(){
    node list;
    list.init();
    node *head=NULL;
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
                if(ch==1) list.insert_begining(num);
                else if(ch==2) list.insert_end(num);
                else if(ch==3){
                    cout<<"Enter Position : ";
                    cin>>pos;
                    list.insert_between(num,pos);
                }
                else cout<<"Invalid Input";

		        break;
	    case 2: cout<<"where to Delete\n1.Begining\n2.End\n3.Desired Position\nYour Choice: ";
                cin>>ch;
                if(ch==1) list.begining_delete();
                else if(ch==2) list.end_delete();
                else if(ch==3){
                    cout<<"Enter Position : ";
                    cin>>pos;
                    list.between_delete(pos);
                }
                else cout<<"Invalid Input";
                break;

		case 3: list.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}
    

