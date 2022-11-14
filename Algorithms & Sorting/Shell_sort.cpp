#include <iostream>
using namespace std;
//21BBS0100

void swap (int* arr, int i, int j) {
  const int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void shellsort(int arr[],int n){
    int dist=(n/2);
    for(int i=dist;i>0;i=i/2){
        if(i%2==0)i++;
        for(int j=i;j<n;j++){
            for(int k=j-i;k>=0;k=k-i){
                if(arr[k+i]<arr[k]) swap(arr,(k+i),k);
                else break;

            }
        }
    }
}


int main () {
    int size,arr[20];
	cout<<"\nEnter the Size of the array : ";
	cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter Element "<<i+1<<": ";
        cin>>arr[i];
    }
    shellsort(arr, size);
    cout<<"The sorted array is: ";
	for( int i = 0 ; i < size; i++){
		cout<< arr[i]<<" ";
	}

}