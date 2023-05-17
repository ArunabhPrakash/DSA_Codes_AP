#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

pair<int,int> Pairs(vector<int> &arr,int sum){
	unordered_set<int> map;
	for(int i=0;i<arr.size();i++){
		map.insert(arr[i]);
		int val = sum - arr[i];
		if(map.find(val)!=map.end()){
			cout<<"\nPair: "<<arr[i]<<","<<val;
		}
	}
}
int main(){
	vector<int> arr = {10,5,2,3,-6,9,11};
	int s=4;
	Pairs(arr,s);
}
