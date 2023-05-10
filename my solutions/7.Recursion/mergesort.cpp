#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &array,int s,int e){
	int i=s;
	int m=(s+e)/2;
	int j=m+1;
	vector<int> temp;
	while(i<=m and j<=e){
		if(array[i]<array[j]){
			temp.push_back(array[i]);//no need to maintain k and easy insertion using vector
			i++;
		}
		else{
			temp.push_back(array[j]);
			j++;
		}
	}
	while(i<=m){
		temp.push_back(array[i++]);
		
	}
	while(j<=e){
		temp.push_back(array[j++]);
	}
	int k=0;
	for(int idx = s;idx<=e;idx++){//make sure to not write idx=0 rookie mistake
		
		array[idx] = temp[k++];
	}
	return;
}

void mergesort(vector<int> &array,int s,int e){//since pass by reference so no need to return any array
	if(s>=e){
		return;
	}
	
	int mid=(s+e)/2;
	mergesort(array,s,mid);
	mergesort(array,mid+1,e);
	return merge(array,s,e);
}

int main(){
	vector<int> array{10,5,2,0,7,6,4};
	int s=0;
	int e=array.size()-1;
	mergesort(array,s,e);
	for(int i=0;i<array.size();i++){
		cout<<array[i]<<" ";
	}
}
