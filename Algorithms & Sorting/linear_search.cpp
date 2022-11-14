#include <bits/stdc++.h>
using namespace std;


void linear_search(int arr[],int n,int target){
    int flag=0,index;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            flag=1;
            index=i;
            break;
        }
    }
    if(flag==1) cout<<"Element found at index "<<index;
    else cout<<"Element not found";
    
}


int main(){
    int size,arr[20],target;
	cout<<"\nEnter the Size of the array : ";
	cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter Element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Enter Element to search for : ";
    cin>>target;
    linear_search(arr,size,target);
}