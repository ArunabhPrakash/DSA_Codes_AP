#include<iostream>
#include<algorithm>
using namespace std;

void printpair(int arr[],int n,int key){
	int sum=0;
	int dist=0;
	int pair=1000;
	int x=-1;
	int y=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sum=arr[i]+arr[j];
			dist=sum-key;
			if(dist<=-1){
				dist=-dist;
			}
			pair=min(pair,dist);
			if(pair==dist){
				x=i;
				y=j;
			}
		}
	}
	cout<<arr[x]<<","<<arr[y];
}

int main(){
	
	int arr[]={1,3,5,7,9};
	int n=sizeof(arr)/sizeof(int);
	int key;
	cin>>key;
	printpair(arr,n,key);
}
