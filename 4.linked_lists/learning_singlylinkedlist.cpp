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
    
            void reverselist(){
                node * prev=NULL;
                node * curr=head;
                node *succ=curr->next;
                while(succ!=NULL){
                    curr->next=prev;
                    prev=curr;
                    curr=succ;
                    succ=succ->next;
                }
                curr->next=prev;
            }
            node* reverse(node* head)
            {
                if (head == NULL || head->next == NULL)
                    return head;
                // Recursive call
                node* rest = reverse(head->next);
                head->next->next = head;
        
                head->next = NULL;
 
                return rest;
            }

            void middleelement(){
                node *slow=head,*fast=head;
                if(head!=NULL){
                    while(fast!=NULL && fast->next!=NULL){
                        slow=slow->next;
                        fast=fast->next->next;

                    }
                    cout<<"MIddle moset element is : "<<slow->data;
                }

            }
            
        

};





int main(){
    node list;
    list.init();
    node *head=NULL;
    
    list.insert_begining(4);
    list.insert_begining(3);
    list.insert_begining(2);
    
    
    
    list.display();
    cout<<"List After Reversing "<<endl;
    list.reverse(head);
    list.display();
    //list.middleelement();
    /*cout<<"after beginging delete :"<<endl;
    list.begining_delete();
    list.display();
    cout<<"after end delete : "<<endl;
    int y=list.end_delete();
    cout<<"Deleted item is : "<<y<<endl;
    list.display();
    list.between_delete(2);
    cout<<"after delete in between : "<<endl;
    list.display();*/

}
