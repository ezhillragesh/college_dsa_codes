#include<iostream>
#include<string.h>
using namespace std;
#define MAX 30

  char a[MAX];  
   int top;

void init()
{
     top=-1;
}
void push(char data)
{
     top++;
     a[top]=data;
     
}
char pop()
{   if(top!=-1)
    { int x=a[top];
    
       top--;
       return x;
	}
    else
      return('\0');
}
int priority(char data)
{
    if(data=='*'||data=='/'||data=='%')
       return 3;
   else if(data=='-'||data=='+')
       return 2;
   else if(data=='>' || data == '<')  
      return 1;  
    else
      return 0;
}



void infix_to_postfix()
{
  int len,j,k=0;
  char opr;
  string s,post;
  cout<<"enter the infix expression to be converted\n";
  getline(cin,s);   
            
  len=s.length();  
  init();
  
  for(j=0;j<len;j++)  
  {
     if((s[j]==' ')||(s[j]=='\t'))  
      continue;
     else if((isdigit(s[j]))||(isalpha(s[j])))  
     {                                                       
      post.append(1,s[j]);                                      
    }
    else if(s[j]=='(')                                 
      push(s[j]);
    else if(s[j]==')')                             
    {
       do
       {
	 opr=pop();                       
	 if(opr=='(')    
	   break;
	 else
	  post.append(1,opr);                      
	 }while (opr!='(');       
    }
    else                                    
    {
	if(top== -1)         
	  push(s[j]);            
	else
	{
	opr=pop(); 
	if(opr=='(')
	{
	  push(opr);
	  push(s[j]);
	}  
	else
	{        
    while(priority(opr)>=priority(s[j]))  
	{                                           
	    post.append(1,opr);                   
	    opr=pop();
	    if(opr=='\0')
	      break;
	}
	push(opr);                
	push(s[j]);               
      } 
	  }                                    
    }                                       
  }    
  char x;
  do 
  { x=pop();
    if (x!='\0')
	  post.append(1,x);
   }while (x!='\0');
  post.append(1,'\0');    
  cout<<post;
  
}



int main(){
    infix_to_postfix();
}