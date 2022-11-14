#include <bits/stdc++.h>
using  namespace std;

//Iterative approach
/*
int main(){
    //Given Sorted Array
    int arr[]={1,3,5,13,20,25,40,42,44,53};
    int start,end,mid,target,i=0;
    target=41;//To be given by the user
    start=0;
    end=size(arr)-1;
    
    while(start<end){
        mid=(start+end)/2;
        if(arr[mid]==target){
             cout<<"Elemnt found at index : "<<i;
             break;
        }
        else if(target<arr[mid]) end=mid-1;
        else start=mid+1;
        i++;
    }
    
}
*/

//Recusive function 

int binarysearch(int start,int end,int target){
    
    if(start>end) return;
    int mid=(start+end)/2;
    if(arr[mid]==target) cout<<"Element found ";
    else if(target<arr[mid]) binarysearch(start,mid-1,target);
    else binarysearch(mid+1,end,target)


}