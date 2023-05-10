#include<iostream>
#include<vector>
using namespace std;

bool notOrder(int i,vector<int> &arr){
	if(i==0){
		return arr[i]>arr[i+1];
	}
	else if(i==arr.size()-1){
		return arr[i]<arr[i-1];
	}
	else{
		return arr[i]>arr[i+1] or arr[i]<arr[i-1];
	}
}
pair<int,int> subarrsort(vector<int> &arr){
	int largest = INT_MIN;
	int smallest = INT_MAX;
	for(int i=0;i<arr.size();i++){
		if(notOrder(i,arr)){
			cout<<arr[i];
			largest = max(largest,arr[i]);
			smallest = min(smallest,arr[i]);
		}
	}
	if(largest==INT_MIN and smallest==INT_MAX){
		return {-1,-1};
	}
	else{
		int i=0;
		while(smallest>arr[i]){
			i++;
		}
		int ind_lb = i;
		i=arr.size()-1;
		while(largest<arr[i]){
			i--;
		}	
		int ind_Ub = i;
		return {ind_lb,ind_Ub};//positions are starting from 0 index,
	}
}
int main(){
	vector<int> arr={1,2,3,4,5,8,6,7,9,10,11};
	pair<int,int> result=subarrsort(arr);
	cout<<result.first<<" "<<result.second;
}
