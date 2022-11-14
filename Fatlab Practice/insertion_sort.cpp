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
void insertion_sort(int arr[],int n){
    //insert an element from unsorted array to its 
    //crt position in sorted array
    //move bigger elements backwards for ascending
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr && j>=0){
            arr[j+1]=arr[j];
            j--; 
        }
        arr[j+1]=curr;
    }

}


int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    display(a,n);
    cout<<endl;
    insertion_sort(a,n);
    display(a,n);

    
    

}