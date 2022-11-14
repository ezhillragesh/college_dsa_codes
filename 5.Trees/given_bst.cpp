#include<iostream>
using namespace std;
class node
{
 node *left;
 node *right;
 int data;
 public:
 node *root=NULL;   
node* insert(node *root,int info) {               
  if(root==NULL)   {
  	root=new node;
  	root->data=info;
  	root->left=NULL;
  	root->right=NULL;   }
  else   {    
  	if(info<root->data)  
      root->left=insert(root->left,info);
  	else 
    root->right=insert(root->right,info);}
  return root;
}
void inorder(node *root)
{                   
	if(root!=NULL)   
	{
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	}
	return;
}
void preorder(node *root)
{
	if(root!=NULL) 
	{
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	}
	return;
}
void postorder(node *root)
{
	if(root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
    cout<<root->data<<" ";
	}
}
node* inordersucc(node *isucc)
{                    
  if(isucc==NULL)          
    return NULL;
  while(isucc->left!=NULL)  
    isucc=isucc->left;
  return isucc;
}
node* del(node *root,int info)
{          
  node *temp;
  if(root==NULL) 
    cout<<"element not present";
  else if(info<root->data) 
   root->left=del(root->left,info);
  else if(info>root->data) 
    root->right=del(root->right,info);
  else 
  {
  	if(root->left!=NULL&&root->right!=NULL)
  	{
  		 temp=inordersucc(root->right);
  		 root->data=temp->data;
  		 root->right=del(root->right,root->data);
	  }
	else
	{
		temp=root;
		if(root->left!=NULL) 
		 root=root->left;
		else if(root->right!=NULL) 
		  root=root->right;
		else
		  root=NULL;
		delete(temp);
	} 
  } 
  return root;

}
};
int main()
{
int choice,info,count=0;
node obj;
cout<<"enter the data to be inserted\n";
cin>>info;     
obj.root=obj.insert(obj.root,info); 
do                   
{
  cout<<"do u want to continue\n1-insert 2-delete\n";
  cout<<"3-preorder 4-inorder 5-postorder 6-exit\n";
  cin>>choice;
  switch(choice)
  {
	case 1: cout<<"enter the data to be inserted\n";
	        cin>>info; 
	        obj.root=obj.insert(obj.root,info);
           	break;      
	case 2: cout<<"enter the value to be deleted\n";
			cin>>info; 
			obj.root=obj.del(obj.root,info);
			break;   
	case 3: obj.preorder(obj.root);
			break;
	case 4: obj.inorder(obj.root);
			break;
	case 5: obj.postorder(obj.root);
			break;
	case 6: exit(0);
	}
	}while(choice!=6);
}