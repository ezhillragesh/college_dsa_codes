#include <iostream>
using namespace std;

void Tower(char s,char d,char i,int n){
    if(n==1){
        cout<<"move disk  "<<n<<"  from "<<s<<"  to  "<<d<<endl;
        return;
    }
    Tower(s,i,d,n-1);
    cout<<"move disk  "<<n<<"  from"<<s<<"  to  "<<d<<endl;
    Tower(i,d,s,n-1);

}

int main(){
    int n=40;
    char s='A',i='B',d='c';
    Tower(s,d,i,n);
}