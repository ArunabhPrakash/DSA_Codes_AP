#include<iostream>
using namespace std;

void insertion_sort(int a[],int n){
	for(int i=1;i<=n-1;i++){//since first ele is already sorted
		int current = a[i];
		int prev=i-1;
		while(prev>=0 and a[prev]>current){
			a[prev+1]=a[prev];
			prev=prev-1;
		}
		a[prev+1]=current;
	}
}

int main(){
	int arr[]={-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);
	insertion_sort(arr,n);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}	
	
	return 0;
}
