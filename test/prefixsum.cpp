#include<iostream>
using namespace std;

void subarrsumprefix(int arr[],int n){
	int prefix[100]={0};
	int largest=0;
	int sum=0;
	for(int i=0;i<n;i++){
		if(i==0){
			prefix[i]=arr[i];
			
		}
		else{
			prefix[i]=arr[i]+prefix[i-1];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			sum=prefix[j]-prefix[i-1];
			largest=max(sum,largest);
			cout<<sum<<endl;
		}
	}
	cout<<"\nLargest:"<<largest;
}
int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	subarrsumprefix(arr,n);

}
