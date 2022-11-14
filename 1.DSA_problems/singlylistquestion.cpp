/*Consider a singly linked list with 13 nodes. All the nodes store the 
value ‘0’ initially. In the first iteration, all the nodes which are 
multiples of one, are incremented by one. In the second iteration, 
those nodes which are multiples of two, are incremented by one. 
Likewise, in the third iteration, those nodes which are multiples 
of three, are incremented by one. Write a program to print the list 
elements after performing ‘n’ such iterations.*/

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    public:
        node*head;
        int init(){
            head=NULL;
        }
        void insert(int d){
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
        void display(){
            node*temp=head;
            while(temp->next!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
                
            }
            cout<<endl;
        }
        
        void solution(int n){
            int count =1;
            node *temp=head;
            while(temp->next!=NULL){
                if((count%n)==0) temp->data+=1;
                temp=temp->next;
                count++;
            }
            
        }

};




int main(){
    node obj;
    int n;
    obj.init();
    for(int i=0;i<=13;++i){
        obj.insert(0);
    }
    obj.display();
    cout<<endl;
    cout<<"Enter n :";
    cin>>n;
    for(int i=1;i<=n;++i){
        obj.solution(i);
        obj.display();
    }
    obj.display();


}