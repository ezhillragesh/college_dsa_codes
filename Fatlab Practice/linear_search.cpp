#include <bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void linearsearch(int a[],int n,int target){
    int flag=0,count=0;
    for(int i=0;i<n;i++){
        count++;
        if(a[i]==target){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"Element found at index : "<<count-1;
    }
    else cout<<"Element not found ";
}

int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    linearsearch(a,n,46);
}