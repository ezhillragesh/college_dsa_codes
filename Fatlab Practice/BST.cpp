#include <bits/stdc++.h>
using namespace std;

class tnode{
    public:
    int data;
    tnode *l,*r;
    tnode(int val){
        data=val;
        l=NULL;
        r=NULL;
    }

};

tnode *insertbst(tnode *root,int val){
    if(root==NULL){
        root=new tnode(val);
        return root;
    }
    else{
        if(val<(root->data)){
            root->l=insertbst(root->l,val);//go left as the value is small
        }
        else{
            root->r=insertbst(root->r,val);
        }
    }
    return root;
}

void postorder(tnode *root){//left root right
    if(root!=NULL){
        postorder(root->l);
        postorder(root->r);
        cout<<root->data<<" ";
    }
}
tnode *searchbst(tnode *root,int key){
    if(root==NULL) return NULL;
    else if(key>root->data)return searchbst(root->r,key);
    else if(key<root->data)return searchbst(root->l,key);
    else return root;
}
tnode *inordersucc(tnode* elem){
    //*inorder succ-- Go right then left then go deeeeep down
    if(elem==NULL) return NULL;
    while(elem && elem->l!=NULL){
        elem=elem->l;
    }
    return elem;
}

tnode *deletebst(tnode *root,int key){
    
    if(root==NULL) cout<<"Element Nahi Haaaaaaai";
    else if(key<root->data){//key less than root the go left
        root->l=deletebst(root->l,key);

    }
    else if(key>root->data){//key greater than root the go right
        root->r=deletebst(root->r,key);

    }
    else{
        if(root->l==NULL){
            tnode *temp=root->r;
            delete(root);
            return temp;
        }
        else if(root->r==NULL){
            tnode *temp=root->l;
            delete(root);
            return temp;
        }
        else{
            tnode *temp=inordersucc(root->r);
            root->data=temp->data;
            root->r=deletebst(root->r,root->data);
        }
    }

    return root;
}

int main(){
    tnode *root=NULL;
    root=insertbst(root,2);
    insertbst(root,21);
    insertbst(root,32);
    insertbst(root,28);
    int v=root->data;
    cout<<v<<endl;
    postorder(root);
    
    searchbst(root,2); 
    int c=root->data;
    cout<<c<<endl;
}





