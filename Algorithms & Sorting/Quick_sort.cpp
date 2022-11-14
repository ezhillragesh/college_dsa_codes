#include <bits/stdc++.h>
using namespace std;
void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int PIndex = low;
    
	
    for(int i=low;i<=high;i++) {   
        
        
        if(arr[i]<=pivot) {
            
            swap(arr[PIndex],arr[i]);
            
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}
void quickSort(int arr[], int low, int high){
	if(low < high) {
	    int pivot = arr[high];
        
            
	    int PIndex = partition(arr, low, high, pivot);
	
            
            quickSort(arr, low, PIndex-1);
            quickSort(arr, PIndex+1, high);
	}
}

int main()
{
	int size,arr[20];
	cout<<"\nEnter the Size of the array : ";
	cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter Element "<<i+1<<": ";
        cin>>arr[i];
    }
    
	quickSort(arr, 0 , size-1);
    
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < size; i++){
		cout<< arr[i]<<" ";
	}
	
    
}