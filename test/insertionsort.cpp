#include<iostream>
using namespace std;
void insertionsort(int arr[],int n){
	for(int i=1;i<=n-1;i++){
		int current=arr[i];
		int prev=i-1;
		while(arr[prev]>current and prev>=0){
			arr[prev+1]=arr[prev];
			prev=prev-1;
		}
		arr[prev+1]=current;
	}
}
int main(){
	int arr[]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(int);
	insertionsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
