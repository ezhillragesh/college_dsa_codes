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
void quick_sort(int a[],int left,int right){
    if(left>=right) return;
    int pivot=left;
    int l=left,r=right;
    while(l<r){
        while(a[l]<=a[pivot]) l++;
        while(a[r]>a[pivot]) r--;
        if(l<r) swape(&a[l],&a[r]);
    }
    swape(&a[pivot],&a[r]);
    quick_sort(a,l,r-1);
    quick_sort(a,r+1,right);


}
    


int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    display(a,n);
    cout<<endl;
    quick_sort(a,0,n); 
    display(a,n);

    
    

}