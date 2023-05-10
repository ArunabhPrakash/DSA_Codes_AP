#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n){
	for(int times=1;times<=n-1;times++){//for n items n-1 sorting req
		for(int j=0;j<=n-times-1;j++){//since "times" starts from 1, max j can go is up to 7 when n is 9
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
}

int main(){
	int arr[]={-2,3,4,-1,5,-12,6,1,3};
	int n=sizeof(arr)/sizeof(int);
	bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

