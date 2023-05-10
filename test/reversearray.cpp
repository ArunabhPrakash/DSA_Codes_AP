#include<iostream>
using namespace std;

void reversearray(int arr[],int n){
	int s=0;
	int e=n-1;
	while(s<e){
		swap(arr[s],arr[e]);
		s+=1;
		e-=1;
	}
}
int main(){
	int arr[]={1,2,3,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(int);
	reversearray(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
