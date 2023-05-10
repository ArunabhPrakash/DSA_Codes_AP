#include<iostream>
#include<ctime>
using namespace std;

bool compare(int a,int b){
	return a>b;
}

void bubble_sort_rec(int a[],int n){
	if(n==1){
		return;
	}
	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1]){
			swap(a[j],a[j+1]);
		}
	}	
	bubble_sort_rec(a,n-1);
}

void bubble_sort_rec2(int a[],int n,int j){
	if(n==1){
		return;
	}
	if(j==n-1){
		bubble_sort_rec2(a,n-1,0);
		return;
	}
	if(a[j]>a[j+1]){
		swap(a[j],a[j+1]);
	}
	bubble_sort_rec2(a,n,j+1);
	
}

int main(){
	int arr[]={-2,3,4,-1,5,-12,6,1,3};
	int n=sizeof(arr)/sizeof(int);
	bubble_sort_rec2(arr,n,0);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
}

