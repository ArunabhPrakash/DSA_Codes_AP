#include<iostream>
using namespace std;
int bubble_sort(int arr[],int n){
	int count=0;
	for(int i=0;i<n-1;i++){
		if(arr[i]<arr[i+1]){
			count++;
		}
	
	}
		if(count == n-1){
			cout<<"sorted";
			return -1;
		}
		
	for(int times=1;times<=n-1;times++){
		for(int j=0;j<=n-times-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	return 1;
}
int main(){
	int arr[]={1,2,3,4,5};
	int n= sizeof(arr)/sizeof(int);
	bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}
