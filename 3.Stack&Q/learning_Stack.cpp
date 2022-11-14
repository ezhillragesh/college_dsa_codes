#include <iostream>
using namespace std;
//21BBS0100
#define MAX 10

class Stack
{
    private:
        int num[MAX];
        int top;
    public:
        Stack(){
    top=-1;
    }    
        int push(int);
        int pop();
        int isempty();
        int isFull();
        void display();
};

 int Stack::isempty(){
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int Stack::isFull(){
    if(top==(MAX-1))
        return 1;
    else
        return 0;
}
 
int Stack::push(int n){
    
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int Stack::pop(){
    
    
    int temp;
    
    if(isempty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void Stack::display(){
    int i; 
    cout<<"Stack is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}

int main(){
    Stack obj;
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
		        obj.push(num);
		        break;
	    case 2: if(!obj.isempty())
	            {
		        popped=obj.pop();
		        cout<<" Popped Item is "<<popped<<"\n";
		        }
		        else
		          cout<<"Stack is Empty\n";
				break;
		case 3: obj.display();
	            break;
	    default: exit(0);
	    
	}
  }while(choice!=4);
}
    
    

