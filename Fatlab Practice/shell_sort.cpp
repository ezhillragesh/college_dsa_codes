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
void shell_sort(int a[],int n){
    int dist=n/2;
    for(int i=dist;i>0;i=i/2){
        if(i%2==0) i++;
        for(int j=i;j<n;j++){
            for(int k=j-i;k>=0;k=k-i){
                if(a[k+i]<a[k]){
                    swape(&a[k+i],&a[k]);
                }//if end
            }//k endS
        }//j end
    }//i end
}//function end


int main(){
    int a[]={24,336,573,57,67,436,7,46},n=8;
    display(a,n);
    cout<<endl;
    shell_sort(a,n);
    display(a,n);

}