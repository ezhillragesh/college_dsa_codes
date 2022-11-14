#include<iostream>
#include<string.h>
#include<stack>
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
int eval(int d1,int d2,char sym) 
{                                                 
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
int postfix_evaluation(string post)
{
  int i,j,val,opd1,opd2;
  
     
   
  i=post.length();  
  init();              
  for(j=0;j<i;j++)     
  {

     if((post[j]==' ')||(post[j]=='\t'))  
      continue; 
     else if(isdigit(post[j]))    
     {      
       val=post[j]-48;    
       push(val);      
     }               
     else if(isalpha(post[j]))  
     {                                                         
      cout<< "Enter the value of "<<post[j]<<" :";
      cin>>val;
      push(val);
     }
    
    else
    {
	opd2=pop();   
	opd1=pop();    
	int x=eval(opd1,opd2,post[j]);
	push(x); 
      }
  }
  cout<<"the result of the give postfix expression is \n"<<pop(); 
  return 0;
}


int prefix_evaluation(string prexp)
{

    
    stack<int> stk;
    int size = prexp.size() - 1;
    int val;
   
   for (int i = size; i >= 0; i--) {

      if (isdigit(prexp[i]))
         stk.push(prexp[i] - '0');
      else if(isalpha(prexp[i]))  
     {                                                         
      cout<< "Enter the value of "<<prexp[i]<<" :";
      cin>>val;
      push(val);
     }
      else {
         int o1 = stk.top();
         stk.pop();
         int o2 = stk.top();
         stk.pop();
         if( prexp[i] == '+')
            stk.push(o1 + o2);
         else if( prexp[i] == '-')
            stk.push(o1 - o2);
         else if( prexp[i] == '*')
            stk.push(o1 * o2);
         else if( prexp[i] == '/')
            stk.push(o1 / o2);
         else{
            cout<<"Invalid Expression";
            return -1;
         }
      }
   }
   cout<<"the result of the give postfix expression is \n"<<stk.top();
}

int main(){
    int ch=0;
    string exp;
    cout<<"Enter the operation to be performed\n1.Postfix Evaluation\n2.Prefix Evaluation \n3.exit\nYOUR CHOICE : ";
    cin>>ch;
    switch(ch)
	{
		case 1:cout<<"Enter postfix Expression : ";
               cin>>exp;
               postfix_evaluation(exp);
               break;
	    case 2:cout<<"Enter prefix Expression : ";
               cin>>exp;
               prefix_evaluation(exp);
		default: exit(0);
	    
	}

}
