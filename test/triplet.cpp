#include<iostream>
using namespace std;

void triplet(int arr[],int n,int key){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int sum=arr[i]+arr[j]+arr[k];
				if(key==sum){
					cout<<arr[i]<<","<<arr[j]<<","<<arr[k]<<endl;
				}	
			}
		}
	}
}
int main(){
	int arr[]={1,2,3,4,5};
	int size=sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	triplet(arr,size,key);
}
