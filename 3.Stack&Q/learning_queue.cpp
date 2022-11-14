#include <iostream>
using namespace std;
//21BBS0100
//Queue using array implementation
/*
#define MAX 10
class queue
{
    int arr[MAX];
    int r,f;            //r---rear f---front
    public:
    void init(){
        r=-1;
        f=-1;
    }
    void enqueue(int d){
        if(r==MAX-1){
            cout<<"q is full";
            
        }
        else{
            r++;
            arr[r]=d;
        }
    }
    int dequeue(){
        if(r==f){
            cout<<"Empty Queue";
            
        }
        else{
            f++;
            return arr[f];
        }
    }
    void display(){
        for(int i=f+1;i<=r;i++){
            cout<<arr[i];
            cout<<"\n";
        }
    }

};

int main(){
    queue obj;
    obj.init();
    int popped;
    int num,choice;
    do
	{
	
	cout<<"Enter the Operation to be performed:\n1.Enqueue\n2.Dequeue\n3.Display\nYour Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"Enter the value you want to insert : ";
		        cin>>num;
		        obj.enqueue(num);
		        break;
	    case 2: 
		        popped=obj.dequeue();
		        cout<<" Popped Item is "<<popped<<"\n";
		        break;
		case 3: obj.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}
*/

//Linked Implementation of queue

class node{
    int data;
    node *next;
    public:
    node *r,*f,*temp;
    void init(){
        r=NULL;
        f=NULL;
    }
    void enqueue(int d){
        node*current=new node();
        current->data=d;
        current->next=NULL;
        if(r==NULL){
            r=current;
            f=current;
        }
        else{
            r->next=current;
            r=current;
        }
    }
    int dequeue(){
        if(r==NULL){
            cout<<"Empty queue";
            return 9999999;
        }
        else{
            int x=f->data;
            node*temp=f;
            f=f->temp;
            delete(temp);
            return x;
        }
    }
    void display(){
        node*temp=f;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            cout<<"\n";
        }
    }
};

int main(){
    node obj;
    obj.init();
    int popped;
    int num,choice;
    do
	{
	
	cout<<"Enter the Operation to be performed:\n1.Push\n2.Pop\n3.Display\nYour Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"Enter the value you want to insert : ";
		        cin>>num;
		        obj.enqueue(num);
		        break;
	    case 2: 
		        popped=obj.dequeue();
		        cout<<" Popped Item is "<<popped<<"\n";
		        break;
		case 3: obj.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}