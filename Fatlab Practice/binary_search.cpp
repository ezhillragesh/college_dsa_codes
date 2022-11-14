#include <bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void binary_search_recur(int a[],int start,int end,int target){
    if(start>end) return;
    int mid= (start+end)/2;
    if(a[mid]==target) cout<<"Element found at index : "<<mid;
    else if(target<a[mid]) return binary_search_recur(a,start,mid-1,target);//left side
    else return binary_search_recur(a,mid+1,end,target);//ryt side

}


void binary_search(int a[],int n,int target){
    int start=0,end=n-1;
    
    while(start<end){
        int mid= (start+end)/2;
        if(a[mid]==target){
            cout<<"Element found at index : "<<mid;
            break;
        } 
        else if(target<a[mid]) end=mid-1;//left side
        else start=mid+1;//ryt side
    }
}

int main(){
    int a[]={7,24,46,57,67,336,436,573},n=8;
    binary_search_recur(a,0,n,7); 
    cout<<endl;
    binary_search(a,n,24);
}