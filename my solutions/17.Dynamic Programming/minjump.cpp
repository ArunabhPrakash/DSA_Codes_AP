#include<iostream>
#include<vector>
using namespace std;

int minJump(vector<int> &arr,int n,vector<int> &dp){//topdown
	if(n>arr.size()-1){
		return 0;
	}
	else{
		if(dp[n]!=-1){
			return dp[n];
		}
		int fV=INT_MAX;
		for(int i=1;i<=arr[n];i++){
			fV= min(fV,1+minJump(arr,n+i,dp));
		}
		return dp[n]=fV;
	}
	
}

int BUDP(vector<int> &arr,int n){//bottom up
	vector<int> dp(arr.size(),-1);
	for(int i=arr.size()-1;i>=0;i--){
		int fV=INT_MAX;
		for(int j=1;j<=arr[i];j++){
			if(j<(n-i)){
				fV=min(fV,1+dp[i+j]);
			}
			else{
				fV=min(fV,1);
			}
		}
		dp[i]=fV;
	}
	cout<<"\n";
		for(auto x:dp){
		cout<<x<<" ";
	}
	return dp[0];
}
int main(){
	vector<int> arr = {3,4,2,1,2,3,10,1,1,1,2,5};
	vector<int> dp(arr.size(),-1);
	cout<<minJump(arr,0,dp)<<"\n";
	for(auto x:dp){
		cout<<x<<" ";
	}
	cout<<"\n"<<BUDP(arr,arr.size());
}
