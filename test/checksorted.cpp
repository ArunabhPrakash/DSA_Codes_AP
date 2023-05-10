#include<iostream>
using namespace std;
bool checksorted(int arr[],int n){
	if(n==1 or n==0){
		return true;
	}
	if(arr[0]<arr[1] and checksorted(arr+1,n-1)){
		return true;
	}
	return false;
}

int main(){
	int arr[]={1,2,3,4,5,6,7};
	int size=sizeof(arr)/sizeof(int);
	if(checksorted(arr,size)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
}
