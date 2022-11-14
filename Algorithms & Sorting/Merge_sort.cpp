#include <iostream>
using namespace std;
//21BBS0100
void merge(int *arr, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    k--;
    while (k >= 0)
    {
        arr[k + low] = temp[k];
        k--;
    }
}

void mergeSort(int *arr, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, size - 1);
    cout<<"The sorted array is: ";
	for( int i = 0 ; i < size; i++){
		cout<< arr[i]<<" ";
	}

    
}