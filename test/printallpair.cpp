#include<iostream>
using namespace std;

void printpair(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout<<"("<<arr[i]<<","<<arr[j]<<")";
		}
	}
}

int main(){
	
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(int);
	printpair(arr,n);
}
