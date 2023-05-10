#include<iostream>
using namespace std;
selectionsort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int min_pos=i;
		for(int j=min_pos;j<n;j++){
			if(arr[j]<arr[min_pos]){
				min_pos=j;
			}
		}
		swap(arr[i],arr[min_pos]);
		
	}
}
int main(){
	int arr[]={-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(arr)/sizeof(int);
	selectionsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
