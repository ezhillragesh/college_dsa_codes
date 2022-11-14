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
void selection_sort(int arr[],int n){
    //Find the minimum element in unsorted array and swap it
    //with element at begining
    for(int i=0;i<n-1;i++){//outer value
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]) swape(&arr[j],&arr[i]);
        }
    }
}


int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    display(a,n);
    cout<<endl;
    selection_sort(a,n);
    display(a,n);

    
    

}