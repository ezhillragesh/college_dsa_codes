#include<iostream>
using namespace std;

int main(){
    int min;
    int arr[]={24,2,14,52,55,46,23,1,29,10};
    for(int i=0;i<=size(arr)-1;i++){
        min=i;
        for(int j=i+1;j<size(arr);j++) if(arr[j]<arr[min]) min=j;
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int i=0;i<=size(arr)-1;i++) cout<<arr[i]<<" ";

    
}
/*
//for descending order
int main(){
    int max;
    int arr[]={24,2,14,52,55,46,23,1,29,10};
    for(int i=0;i<=size(arr)-1;i++){
        max=i;
        for(int j=i+1;j<size(arr);j++) if(arr[j]>arr[max]) max=j;
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
    for(int i=0;i<=size(arr)-1;i++) cout<<arr[i]<<" ";

    
}*/

//Recursive function for Selection sort

 