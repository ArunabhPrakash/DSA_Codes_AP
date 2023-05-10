#include<iostream>
#include<vector>
using namespace std;
bool subarray(vector<int> arr,int val,int k){
	int count=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>=val){
			count++;
		}
		else{
			int sum=arr[i];
			for(int j=i+1;j<arr.size();j++){
				sum=sum+arr[j];
				if(sum>=val){
					count++;
					i=j;
					break;
				}
			}
		}
	}
	if(count>=k){
		return true;
	}
	else{
		return false;
	}
}
int bs(vector<int> arr,vector<int> mosearch,int s,int e,int k){
	if(s>e){
		return -1;
	}
	else{
		int mid=(s+e)/2;
		
		if(subarray(arr,mosearch[mid],k)){
			int val=mosearch[mid];
			return max(val,bs(arr,mosearch,mid+1,e,k));
		}
		else{
			return bs(arr,mosearch,s,mid-1,k);
		}
	}
}
int getCoins(vector<int> arr, int k){
	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum=sum+arr[i];
	}
	vector<int> mosearch;
	for(int i=1;i<=sum;i++){
		mosearch.push_back(i);
	}
	int s=0;
	int e=mosearch.size()-1;
	return bs(arr,mosearch,s,e,k);
}

int main(){
	vector<int> coins={1,2,3,4};//10,22,40,50;32
	int k=3;
	cout<<getCoins(coins,k);
}
