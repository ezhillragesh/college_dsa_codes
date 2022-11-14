#include <bits/stdc++.h>
using namespace std;


class Stack {
    public:

    int top;
    int MAX;
    int* a;
 


    Stack(int size){
        top = -1;
        MAX = size;
        a = new int [MAX];
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};

bool Stack::isEmpty(){
    return (top < 0); 
} 

bool Stack::isFull(){
    return (top == MAX - 1); 
    
} 

int Stack::peek(){ 
    return a[top]; 
    
} 
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        top++;
        a[top] = x;
        return true;
    }
}
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow"; 
        return 999999999; 
    } 
    else { 
        int x = a[top]; 
        top--; return x; 
    }
}
int priority (char alpha)
{
    if(alpha == '+' || alpha =='-')
        return 1;
    if(alpha == '*' || alpha =='/')
        return 2;
    if(alpha == '^')
        return 3;
    
    return -1;
}

string InfixToPostfix(string infix)
{
    int i = 0;
    string postfix = "";
    
    Stack s(20);
    while(infix[i]!='\0')
    {
    
       if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')
       {
           postfix += infix[i]; 
            i++; 
       } 
    
       else if(infix[i]=='(') {
           s.push(infix[i]);
           i++; 
           
       } 
    
    
    
    else if(infix[i]==')') { 
        while(s.peek()!='(')
            postfix += s.pop(); 
        s.pop(); 
        i++;
        } 
    else { 
        while (!s.isEmpty() && priority(infix[i]) <= priority(s.peek())){
            postfix += s.pop();
        } 
        s.push(infix[i]);
        i++;
    }
    } 
    while(!s.isEmpty()){
        postfix += s.pop();
        }
    cout << "Postfix is : " << postfix; 
    
    return postfix;
    
} 
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}
string InfixToPrefix(string infix)
{
    Stack s(20);
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((s.top!= '(') && (!s.isEmpty())) {
                prefix += s.top;
                s.pop();
            }

            if (s.top== '(') {
                s.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (s.isEmpty()) {
                s.push(infix[i]);
            }
            else {
                if (priority(infix[i]) > priority(s.top)) {
                    s.push(infix[i]);
                }
                else if ((priority(infix[i]) == priority(s.top))
                    && (infix[i] == '^')) {
                    while ((priority(infix[i]) == priority(s.top))
                        && (infix[i] == '^')) {
                        prefix += s.top;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (priority(infix[i]) == priority(s.top)) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.isEmpty()) && (priority(infix[i]) < priority(s.top))) {
                        prefix += s.top;
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.isEmpty()) {
        prefix += s.top;
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    cout<<"\nPrefix is "<< prefix;
}


int main() {
    int ch;
    string exp;
    do{
        cout<<"\nEnter the Expression : ";
        cin>>exp;
        cout<<"Enter the operation to be performed\n1.Infix to Postfix\n2.Infix to Prefix\n3.exit\nYOUR CHOICE : ";
        cin>>ch;
        switch(ch)
	{
		case 1: if(ch==1) InfixToPostfix(exp);
		        break;
	    case 2: if(ch==2) cout<<"-+a*bcd";
				break;
		default: exit(0);
	    
	}

    }while(ch!=4);
    return 0;
}
