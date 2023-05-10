#include<iostream>
using namespace std;
int firstocc(int arr[],int n,int key){
	if(n==0){
		return -1;
	}
	if(arr[0]==key){
		return 0;
	}
	int subIndex=firstocc(arr+1,n-1,key);
	if(subIndex!=-1){
		subIndex+=1;
		
	}
	return subIndex;
}

int lastocc(int arr[],int n,int key){
	if(n<0){
		return -1;
	}
	else if(arr[n]==key){
		return n;
	}
	else{
		lastocc(arr,n-1,key);
	}
}
int main(){
	int arr[]={1,2,3,4,7,5,8,9,12,11,7};
	int n=sizeof(arr)/sizeof(int);
	int key=7;
	//cout<<firstocc(arr,n,key);
	cout<<lastocc(arr,n-1,key);
}
