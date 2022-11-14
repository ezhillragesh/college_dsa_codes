#include <bits/stdc++.h>
using namespace std;


void insertion_sort_asc(int arr[],int n){
    int k;
    for(int k=1; k<n; k++)   
    {  
        int temp = arr[k];  
        int j= k-1;  
        while(j>=0 && temp <= arr[j])  
        {  
            arr[j+1] = arr[j];   
            j = j-1;  
        }  
        arr[j+1] = temp;  
    }  
    cout<<"\nSorted list is \n";
    for(int i=0;i<n;i++)  
    {  
        cout <<arr[i]<<" ";  
    }  
}
void insertion_sort_desc(int arr[],int n){
    int k;
    for(int k=1; k<n; k++)   
    {  
        int temp = arr[k];  
        int j= k-1;  
        while(j>=0 && temp >= arr[j])  
        {  
            arr[j+1] = arr[j];   
            j = j-1;  
        }  
        arr[j+1] = temp;  
    }  
    cout<<"\nSorted list is \n";
    for(int i=0;i<n;i++)  
    {  
        cout <<arr[i]<<" ";  
    }  
}

void selection_sort_asc(int arr[],int n){
    int min;
    for(int i=0;i<=n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++) if(arr[j]<arr[min]) min=j;
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int i=0;i<=n-1;i++) cout<<arr[i]<<" ";
}
void selection_sort_desc(int arr[],int n){
    int max;
    for(int i=0;i<=n-1;i++){
        max=i;
        for(int j=i+1;j<n;j++) if(arr[j]>arr[max]) max=j;
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
    for(int i=0;i<=n-1;i++) cout<<arr[i]<<" ";
}





int main(){
    int ch,size,arr[20];
    do
	{
	
	
    cout<<"\nOperation to be Performed:\n1.Insertion Sort(Ascending Order)\n2.Insertion Sort(descending Order)\n3.Selection Sort(Ascending Order)\n4.Selection Sort(descending Order)\n5.exit\nYour Choice : ";
    cin>>ch;
    cout<<"\nEnter the Size of the array : ";
	cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter Element "<<i+1<<": ";
        cin>>arr[i];
    }

	switch(ch)
	{
		case 1: insertion_sort_asc(arr,size);
		        break;
	    case 2: insertion_sort_desc(arr,size);
		        break;
		case 3: selection_sort_asc(arr,size);
                break;
        case 4: selection_sort_desc(arr,size);
                break;
	    default: cout<<"INVALID INPUT";
	    
	}
  }while(ch!=5);
}
    
