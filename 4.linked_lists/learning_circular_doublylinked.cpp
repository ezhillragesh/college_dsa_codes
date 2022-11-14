#include<bits/stdc++.h>
using namespace std;

class cnode{
    public:
    int data;
    cnode*succ;
    cnode*prev;
    cnode(int val){
        data=val;
        succ=NULL;
        prev=NULL;
    }
};

void insertbeg(cnode * &head,int val){
    cnode*current=new cnode(val);
    if(head==NULL){
        current->succ=current;
        current->prev=current;
        head=current;
    }
    cnode *temp=head;
    while(temp->succ!=head) temp=temp->succ;
    temp->succ=current;
    current->succ=head;
    current->prev=temp;//!ook
    head=current;
    
void insert_end()
{
 
    int info;    
 
    cout<<"Enter the value that has to be inserted at last:";
    cout<<info;
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        cout<<"Initially the list is empty and now new node is inserted but at first";
        first = last = new;
        first->next = last->next = NULL;    
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}
    
        
}

void display(cnode *head){
    cnode *temp=head;
   do
    {
        cout<<temp->data<<" ";
        temp=temp->succ;
    } while (temp!=head);
    cout<<endl;
}



int main(){
    cnode*head=NULL;
    insertbeg(head,3);
    insertbeg(head,6);
    
    display(head);
}






  bool search(int value)
    {
        Dnode* current = First;
        for (int i = 0; i < Count; i++)
        {
            if (current->Value == value)
            {
                return true;
            }

            current = current->Next;
        }

        return false;
    }
};