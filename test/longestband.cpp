#include<iostream>
#include<algorithm>
using namespace std;

int longestband(int arr[],int n){
	int count=0;
	int mc=0;
	sort(arr,arr+n);

	for(int i=0;i<n;i++){
		if(arr[i+1]-arr[i]==1){
			count++;
			
		}
		else{
			count++;
			mc=max(count,mc);
			count=0;
		}
	}
	return mc;
}
int main(){
	int arr[]={1,9,3,0,18,5,2,10,7,12,6};
	int n= sizeof(arr)/sizeof(int);
	cout<<longestband(arr,n);
}
