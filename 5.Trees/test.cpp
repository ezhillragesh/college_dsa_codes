#include <bits/stdc++.h>
using namespace std;
//21BBS0100
class Tnode{
    public:
    int data;
    Tnode *left,*right;
    Tnode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


Tnode* insertBST(Tnode * root,int val){
    if(root==NULL) {
        root=new Tnode(val);
        return root;
    }
    else{
        if(val<root->data) root->left=insertBST(root->left,val);
        else root->right=insertBST(root->right,val);
    }
    return root;
}

void inorder(Tnode *root){//!Left--Root--Right
    if(root!=NULL)   
	{
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	}
    
	return;
}

void preorder(Tnode *root){//!Root--Left--Right
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    
    return;
}

void postorder(Tnode* root){//!Left--Right--Root
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

}
Tnode* searchinBST(Tnode* root,int key){
    if(root==NULL) return NULL;//if element is not present
    if(root->data==key) return root;//if element is the root
    //data less than key
    if(root->data>key) return searchinBST(root->left,key);
    ///data greater than key
    return searchinBST(root->right,key);

}

Tnode *inordersucc(Tnode* elem){
    //*inorder succ-- Go right then left then go deeeeep down
    if(elem==NULL) return NULL;
    while(elem && elem->left!=NULL){
        elem=elem->left;
    }
    return elem;
}

/* 
    !DELETION IN BINARY SEARCH TREEE
    !Case 1:Leaf Node(No child):
            Just Delete the elment and if ETBD is left Child then make the parent Left NULL and VICEVERSA
    !Case 2: Element Has EK(1) Child:
            ?a)left child of parent:
                make its child as parents left child
            ?b)right child of parent:
                make its child as parents right child
    !Case 3: Element Has DHO(2) Beta:
            ?Find the inorder succ or preorder prec  and replace then delete the succ oor prec
            *inorder succ-- Go right then left then go deeeeep down
            *preorder prec-- Go left then Rigth the go deeeeep down

*/

Tnode *deleteinBST(Tnode * root,int key){
    Tnode *temp;
    //?Searching in the Tree
    if(root==NULL) cout<<"Element Nahi Haaaaaaai";
    else if(key<root->data){//key less than root the go left
        root->left=deleteinBST(root->left,key);

    }
    else if(key>root->data){//key greater than root the go left
        root->right=deleteinBST(root->right,key);

    }
    //!!NOW THE ELEMENT IS FOUND!!!
    else{
        if(root->left==NULL){//!Ek beta right wala
            Tnode *temp=root->right;
            delete(root);
            return temp;

        }
        else if(root->right==NULL){//!Ek beta left wala
            Tnode *temp=root->left;
            delete(root);
            return temp;

        }

        //!CASE 3
        temp=inordersucc(root->right);
        root->data=temp->data;
  		root->right=deleteinBST(root->right,root->data);
    }
    return root;

}


int main(){
    
    
    int n,val,choice;
    Tnode *root=NULL;
    cout<<"Enter the number of Element to be inserted : ";
    cin>>n;
    for(int i=0;i<n;++i){
        if(i==0){
            cout<<"Enter the element 1 : ";
            cin>>val;
            root=insertBST(root,val);

        }
        else{
        cout<<"Enter the element "<<i+1<<": ";
        cin>>val;
        insertBST(root,val);
        }
    }
    
    do
	{
	
	cout<<"\nOperation to be performed\n1.Deletion\n2.Traversal\n3.Search\nYour Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"\n Enter the Element to be Deleted : ";
                cin>>val;
                deleteinBST(root,val);
		        break;
	    case 2: cout<<"\nPost order Traversal : ";
                postorder(root);
                cout<<"\nPre order Traversal : ";
                preorder(root);
                cout<<"\nInorder Traversal : ";
                inorder(root);
                break;
		case 3: cout<<"Enter elemnt to be found : ";
                cin>>val;
                if(searchinBST(root,val)!=NULL) cout<<"Element Found";
                else cout<<"Element Not Found";
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}


    






    
    
