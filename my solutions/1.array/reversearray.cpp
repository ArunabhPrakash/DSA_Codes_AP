#include<iostream>
using namespace std;

void reverseArray(int arr[],int n){
	int s=0;
	int e=n-1;
	while(s<e){
		swap(arr[s],arr[e]);
		s+=1;
		e-=1;
	}
}
void singlePointer(int arr[],int size){
	for(int i=0;i<size/2;i++){
		swap(arr[i],arr[size-i-1]);
	}
}
int main(){
	int arr[]={10,20,30,45,60,80,90};
	int n=sizeof(arr)/sizeof(int);
	//reverseArray(arr,n);
	singlePointer(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"";
	}
	cout<<endl;
	return 0;
	
}
