/*
//Program to implement stack using array

#include <iostream>
using namespace std;
#define MAX 10

class Stack
{
    private:
        int arr[MAX];
        int top;
    public:
        void init(){
            top=-1;
        }
        void push(int data){
            if(top==MAX-1){
                cout<<"OVERFLOW";
                
            }
            else{
                top++;
                arr[top]=data;
            }
        }
        int pop(){
            if(top==-1){
                cout<<"UNDERFLOW";
                
            }
            else{
                int rm=arr[top];
                top--;
                return rm;
            }
        }
        void display(){
            for(int i=0;i<=top;i++){
                cout<<arr[i];
                cout<<"\n";
            }
        }
    
};
int main(){
    int ch,pop,d;
    Stack st;
    
    ch=1;
    do{
        cout<<"Enter your Choice "<<endl<<"1.push\n2.pop\n3.display\n4.exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter Number to be pushed : ";
                cin>>d;
                st.push(d);
                break;
            case 2:
                cout<<"the poped out element is : "<<st.pop()<<endl;
                break;
            case 3:
                cout<<"THE GIVEN STACK IS "<<endl;
                st.display();
                break;
            default:
                cout<<"INVALID INPUT";

        }

    }while(ch!=4);

}
*/

//implementation of Singly linked list

#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node *head;
        void init(){
            head=NULL;
        }
        void insert_beg(int d){
            node*current=new node();
            current->data=d;
            current->next=NULL;
            if(head==NULL){
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
            while(temp->next!=NULL){
               temp=temp->next;
            }
            temp->next=current;

        }

        void insert_bet(int d,int pos){
            node*current=new node();
            current->data=d;
            current->next=NULL;
            node*temp=head;
            for(int i=1;i<=pos;i++){
                temp=temp->next;
            }
            current->next=temp->next;
            temp->next=current;

        }
        void display(){
            node*temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }

};

int main(){
    int x;
    node n1;
    n1.insert_beg(1);
    n1.insert_end(5);
    n1.insert_beg(22);
    n1.display();
    
}