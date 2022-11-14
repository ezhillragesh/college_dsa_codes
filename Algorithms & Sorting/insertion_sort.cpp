#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[]={24,2,14,52,55,46,23,1,29,10};
    int temp,j,i;
    for(i=1;i<size(a);i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[i];//swapping with previous place if elem 
            j--;
        }
        a[j+1]=temp;

    }
    for(i=0;i<=size(a)-1;i++) cout<<a[i]<<" ";
}




