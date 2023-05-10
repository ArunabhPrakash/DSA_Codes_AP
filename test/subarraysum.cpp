#include<iostream>
using namespace std;

void subarray(int arr[],int n){
	int largest=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				cout<<arr[k]<<",";
				sum+=arr[k];
			}
			cout<<":"<<sum<<endl;
			largest=max(largest,sum);
		}
	}
	cout<<"\nlargest:"<<largest;
}
int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	subarray(arr,n);
}
