#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a,int s,int e){
	int pivot=a[e];
	int i = s-1;
	for(int j=s;j<e;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}
int kthsmallestele(vector<int> &a,int s,int e,int k){

	int p = partition(a,s,e);
	cout<<p<<": "<<a[p]<<endl;
	if(k==p){
		return a[p];
	}
	else if(k<p){
		return kthsmallestele(a,s,p-1,k);
		
	}
	else{
		return kthsmallestele(a,p+1,e,k);
	}
	
}
int main(){
	vector<int> arr{10,5,2,0,7,6,4};
	int n=arr.size();
	int k=3;
	cout<<kthsmallestele(arr,0,n-1,k);
	
}

