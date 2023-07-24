#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//top down :recursion : easier
int minNumberofCoinsForChange(int m,vector<int> denoms){
	vector<int> dp(m+1,0);//set all vals of dp to 0
	dp[0]=0;
	
	for(int i=1;i<=m;i++){
		dp[i]=INT_MAX;
		for(int c : denoms ){
			if(i-c>=0 and dp[i-c]!=INT_MAX){//means if i-c is 12-5 is 7 and dp[i-c] means steps taken to reach 7, for 12 it will be +1 of that
				dp[i]=min(dp[i],dp[i-c]+1);
				
			}
		}
		cout<<dp[i]<<endl;
	}
	return dp[m]==INT_MAX? -1: dp[m];
	
}
int BUM(vector<int> &denom,int target){//bottom up
	vector<int> dp (target+1,-1);
	dp[0]=0;
	for(int i=1;i<=target;i++){
		int fV= INT_MAX;
		for(int j=0;j<denom.size();j++){
			if(denom[j]<=i){
				fV=min(fV,1+dp[i-denom[j]]);
			}
		}
		dp[i]=fV;
		cout<<dp[i]<<" ";
	}
	return dp[target];
}
int main(){
	vector<int> denoms = {1,5,7,10};
	int m=15;
	cout<<minNumberofCoinsForChange(m,denoms);
}
