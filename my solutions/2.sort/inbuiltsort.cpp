#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int arr[]={10,9,8,6,5,4,3,2,11,16,8};
	int n=sizeof(arr)/sizeof(int);
	
	sort(arr,arr+n);//for vector sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}
	reverse(arr,arr+n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<",";
	}
	return 0;
}

