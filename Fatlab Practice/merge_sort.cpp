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

void mergeit(int a[],int low,int high,int mid){
    int temp[30];
    int i=low,j=mid+1,k=low; //i->first element of left,j->first element of right arr,k->first elem of resultant arr
    while(i<=mid && j<=high){//while i and j didn't reach the end of arr
        if(a[i]<=a[j]){
            temp[k++]=a[i++]; 
        }
        else{ 
            temp[k++]=a[j++];
        }

    }//end of while
    while(i<=mid){//in case j reached end faster
        temp[k++]=a[i++];
    }
    while(j<=high){//in case i reached end faster
        temp[k++]=a[j++]; 
    }
    for(i=low;i<=k-1;i++){
        a[i]=temp[i];//copyinSg elements from temp to OG array
    }

}//function end
void msort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        msort(a,low,mid);
        msort(a,mid+1,high);
        mergeit(a,low,high,mid);
    }
}
    


int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    display(a,n);
    cout<<endl;
    msort(a,0,n); 
    display(a,n);

    
    

}