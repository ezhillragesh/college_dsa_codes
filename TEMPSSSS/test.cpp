

/*
int swapord(int *p,int *q)
{
    if(*p>*q){
        int t=*p;
        *p=*q;
        *q=t;
    }
}
int main() 
{
	// your code goes here
	int a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
    swapord(&a,&b);
    swapord(&b,&c);
    swapord(&a,&b);
    cout<<b;
    return 0;
}


#include <iostream>
using namespace std;
#define MAX 20


int main() {
	// your code goes here
	int n,k;
	cin>>n;
	string spa=" ";
	string star="*";
	for(int i=0;i<=n;i++){
	    while(k==n){
	        cout<<(spa*(k-1))<<(star*i);
	        k--;
	    }
	}
	
	return 0;
}


#include <iostream>
using namespace std;

#define MAX 10
//Array implementation of Stack
class stack
{
    public:
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
        void pop(){
            if(top==-1){
                cout<<"UNDERFLOW";
                
            }
            else{
                int rm=arr[top];
                top--;
                
            }
        }
        void display(){
            for(int i=0;i<=top;i++){
                cout<<arr[i];
                cout<<"\n";
            }
        }
    
};

int postfixevaluation(string s){
	stack st;
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])){
			st.push(s[i]-'0');//zero is subtracted to make the input integer
		}
		else{
			int op2=st.top;
			st.pop();
			int op1=st.top;
			st.pop();
		

			switch (s[i])
			{
			case '+':
				st.push(op2+op1); 
				break;
			case '-':
				st.push(op2-op1);
				break;
			case '*':
				st.push(op2*op1);
				break;
			case '/':
				st.push(op2/op1);
				break;

			default:
				cout<<"use given operators only";
				break;
			}

		}
	}
	return st.top;
}

int main(){
	cout<<postfixevaluation("46+2/5*7+")<<endl;
	cout<<"hgc";
	return 0;
}




#include <iostream>
using namespace std;


class node
{
    private:
    int data;
    node *next;
    node *head;

    public:
    node()
    {
        next=NULL;
        head=NULL;
    }
    
    void insert(int d)
    {
        node *cur=new node();
        cur->data=d;
        if(head==NULL)
        {
            head=cur;
            cur->next=NULL;
        }
        else
        {
            cur->next=head;
            head=cur;
        }
    }
    
    void incr(int n)
    {
        int count=1;
        node *temp=head;
        for(int i=0;i<13;i++)
        {
            if((count%n)==0)
                (temp->data)++;
            temp=temp->next;
            count++;
        }
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"List underflow"<<endl;
            return;
        }
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    node obj;
    
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    
    for(int i=0;i<13;i++)
    {
        obj.insert(0);
    }
    
    obj.display();
    for(int i=1;i<=n;i++)
    {
        obj.incr(i);
        obj.display();
    }

}


#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);

    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){

    if(head==NULL){//if list is empty
        insertAtHead(head,val); 
        return;
    }

    node* n = new node(val);
    node* temp=head;

    while(temp->next!=head){//to traverse to the last pointer
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;
}

void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    node* todelete=head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}

void deletion(node* &head, int pos){

    if(pos==1){
        deleteAtHead(head);
        return;
    }
      node* temp=head;
      int count=1;

      while(count!=pos-1){
          temp=temp->next;
          count++;
      }

      node* todelete=temp->next;
      temp->next=temp->next->next;

      delete todelete;
}

void display(node* head){


    node* temp=head;
    
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
    
    
    
}


int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    //deletion(head,1);
    display(head);
    

    return 0;
}

*/


#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
#define N 4
#define M 4
class node {
public:
 int x, y;
 int dir;
 node(int i, int j)
 {
 x = i;
 y = j;
 dir = 0;
 }
};
int n = N, m = M;
int fx, fy;
bool visited[N][M];
bool isReachable(int maze[N][M])
{
 int i = 0, j = 0;

 stack<node> s;

 node temp(i, j);

 s.push(temp);
 while (!s.empty())
{
 temp = s.top();
 int d = temp.dir;
 i = temp.x, j = temp.y;
 temp.dir++;
 s.pop();
 s.push(temp);
 if (i == fx and j == fy) {
 return true;
 }
 if (d == 0) {
 if (i - 1 >= 0 and maze[i - 1][j] and
 visited[i - 1][j]) {
 node temp1(i - 1, j);
 visited[i - 1][j] = false;
 s.push(temp1);
 }
 }
 else if (d == 1) {
 if (j - 1 >= 0 and maze[i][j - 1] and
 visited[i][j - 1]) {
 node temp1(i, j - 1);
 visited[i][j - 1] = false;
 s.push(temp1);
 }
 }
 else if (d == 2) {
 if (i + 1 < n and maze[i + 1][j] and
 visited[i + 1][j]) {
 node temp1(i + 1, j);
 visited[i + 1][j] = false;
 s.push(temp1);
 }
 }
 else if (d == 3) {
 if (j + 1 < m and maze[i][j + 1] and
 visited[i][j + 1]) {
 node temp1(i, j + 1);
 visited[i][j + 1] = false;
 s.push(temp1);
 }
 }
 else {
 visited[temp.x][temp.y] = true;
 s.pop();
 }
 }
 return false;
}
int main()
{
 memset(visited, true, sizeof(visited));
 int maze[N][M] = {
 { 1,2,3,4},
 { 5,6,7,8},
 { 9,10,11,12},
 {13,14,15,16 }
 };
 fx = 1;
 fy = 16;
}