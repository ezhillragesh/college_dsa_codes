#include<iostream>
#include<string.h>
#define MAX 30
using namespace std;

  int a[MAX];
   int top;

void init()
{
     top=-1;
}
void push(int data)
{
     int i;
     top++;
     a[top]=data;
}
int pop()
{
     return(a[top--]);
}
int eval(int d1,int d2,char sym) // this function takes 2 operands and 1 operator as input parameters
{                                                 // and evaluates the 2 operands based on the operator and returns the result
    int r;
    switch(sym)
    {
      case '+':  r=d1+d2; break;
      case '-':  r=d1-d2; break;
      case '*':  r=d1*d2; break;
      case '/':  r=d1/d2; break;
      case '%':  r=d1%d2; break;
    }
    return(r);
}
int main()
{
  int i,j,val,opd1,opd2;
  
  string post;   //34+
  printf("enter the postfix expression to be evaluated\n");
  getline(cin,post); //34+
  i=post.length();  //3  
  init();              
  for(j=0;j<i;j++)     //"34+"   //ab+  post[0] ='a' post[1]='b'  post[2]='+'
  {

     if((post[j]==' ')||(post[j]=='\t'))  
      continue; 
     else if(isdigit(post[j]))    
     {      //'3'-'0'  post[j]-'0'
       val=post[j]-48;    // if the operands in the expression are digits, directly we can use the value of the           
       push(val);      // current operand and push it
     }               //'a'
     else if(isalpha(post[j]))  // if the operand is an alphabet, get the input for the operand and use it for 
     {                                                         // further processing and push it
      cout<< "enter the value of "<<post[j];
      cin>>val;
      push(val);
     }
    
    else
    {
	opd2=pop();   // if the current character is an operator, pop the 2 topmost elements from 
	opd1=pop();    // stack and call eval function to evaluate them. Push the value returned by that 
	int x=eval(opd1,opd2,post[j]);
	push(x); // function onto the stack
      }
  }
  cout<<"the result of the give postfix expression is \n"<<pop(); // pop the result and display
  return 0;
}