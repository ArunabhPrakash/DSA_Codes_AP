#include<iostream>
#include<vector>
using namespace std;
void countsort(int arr[],int n){
	int largest=INT_MIN;
	for(int i=0;i<n;i++){
		largest=max(largest,arr[i]);
		
	}
	vector<int> freq(largest+1,0);
	for(int i=0;i<n;i++){
		freq[arr[i]]++;
	}
	int j=0;
	for(int i=0;i<=largest;i++){
		while(freq[i]>0){
			arr[j]=i;
			j++;
			freq[i]--;
		}
	}
	
}
int main(){
	int arr[]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(int);
	countsort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
