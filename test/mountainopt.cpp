#include<iostream>
using namespace std;

int sizeofmt(int arr[],int n){
	int count=0;
	int mc=0;
	for(int i=0;i<n;i++){
		if((i-1)!=-1 or (i+1)!=n){
			
			if(arr[i-1]>arr[i] and arr[i]<arr[i+1]){
				count++;
				mc=max(count,mc);
				count=1;
			}
			else{
				count++;
			}
		}
		else if(int (i-1)==-1){
			if(arr[i]<arr[i+1]){
				count++;
			}
			
		}
		else{
			if(arr[i-1]>arr[i]){
				count++;
				mc=max(count,mc);
				count=1;
			}
		}
	
	}
	return mc;
	
}
int main(){
	int arr[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	int n=sizeof(arr)/sizeof(int);
	cout<<sizeofmt(arr,n);
}
