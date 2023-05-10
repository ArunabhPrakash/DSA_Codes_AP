#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void findpair(vector<int> &arr,int sum){
	unordered_map<int,int> mappy;
	for(int i=0;i<arr.size();i++){
		int val = sum-arr[i];
		if(mappy.count(val)!=0){
			cout<<arr[mappy[val]]<<" "<<arr[i]<<endl;
		}
		mappy[arr[i]]=i;
	}
}
int main(){
	vector<int> arr={10,5,2,3,-6,9,11,-1,-5,1,-7};
	int sum=4;
	findpair(arr,sum);
}
