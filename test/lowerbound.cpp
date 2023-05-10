#include<iostream>
using namespace std;

int lowerbound(int arr[],int n,int key){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return arr[i];
		}
		else if(key<arr[i] and i!=0){
			return arr[i-1];
		}
	}
	return -1;
}
int main(){
	int arr[]={1,3,5,7,9};
	int n=sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	cout<<lowerbound(arr,n,key);
}
