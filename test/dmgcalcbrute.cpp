#include<iostream>
using namespace std;

int calcoptlife(int arr[],int n,int armor){
	int Td=INT_MAX;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(i==j){
				int block=min(arr[j],armor);
				int dmg = arr[j]-block;
				sum+=dmg;
			}
			else{
				sum+=arr[j];
			}
		}
		Td=min(sum,Td);
	}
	return Td+1;
}
int main(){
	int arr[]={1,3,6,4};
	int n=sizeof(arr)/sizeof(int);
	int armor=5;
	cout<<calcoptlife(arr,n,armor);
}
