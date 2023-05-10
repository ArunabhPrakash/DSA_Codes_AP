#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int s,int e){
	int i=s;
	int m=(s+e)/2;
	int j=m+1;
	vector<int> temp;
	while(i<=m and j<=e){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
		}
		
	}
	while(i<=m){
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=e){
		temp.push_back(arr[j]);
		j++;
	}
	int k=0;
	for(int i=s;i<=e;i++){
		arr[i]=temp[k];
		k++;
	}
	return;
}
void mergesort(vector<int> &arr,int s,int e){
	if(s>=e){
		return;
	}
	int m=(s+e)/2;
	mergesort(arr,s,m);
	mergesort(arr,m+1,e);
	merge(arr,s,e);
	return;
}
int main(){
	vector<int> arr={10,10,5,2,0,7,6,4};
	int s=0;
	int e=arr.size()-1;
	mergesort(arr,s,e);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
}
