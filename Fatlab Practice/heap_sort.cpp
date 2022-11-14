#include <bits/stdc++.h>
using namespace std;

void swape(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void heap_sort(int a[],n){}
    


int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    display(a,n);
    cout<<endl;
    heap_sort(a,n); 
    display(a,n);
}