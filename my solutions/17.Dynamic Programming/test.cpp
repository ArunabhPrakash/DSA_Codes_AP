#include<iostream>
#include<vector>
using namespace std;

int maxNonAdjacentSum(vector<int> &arr,int n,vector<int> &dp){//topdown
	if(n<0){
		return 0;
	}
	else{
		if(dp[n]!=-1){
			return dp[n];
		}
		int inc = arr[n]+maxNonAdjacentSum(arr,n-2,dp);
		int exc = maxNonAdjacentSum(arr,n-1,dp);
		return dp[n]=max(inc,exc);
	}
}
int main(){
	vector<int> arr = {6,10,12,7,9,14};
	vector<int> dp (arr.size(),-1);
	cout<<maxNonAdjacentSum(arr,arr.size()-1,dp);
}
