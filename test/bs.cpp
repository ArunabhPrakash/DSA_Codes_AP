#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int key){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=(s+e)/2;
		if(key==arr[mid]){
			return mid;
		}
		else if(arr[mid]>key){
			e=mid-1;
		}
		else{
			s=mid+1;
		}
		
	}
	return -1;
}
int main(){
	int arr[]={3,5,7,8,10,13,15};
	int n=sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	cout<<binarysearch(arr,n,key);
	
}
