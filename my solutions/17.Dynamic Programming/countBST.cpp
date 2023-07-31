#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countBST(int start,int end,vector<int> &dp){//topdown
	int dif = end-start+1;
	if(dif==0){
		return dp[dif];
	}
	else{
		if(dp[dif]!=-1){
			return dp[dif];
		}
		int count=0;
		for(int i=start;i<=end;i++){
			int val=countBST(start,i-1,dp)*countBST(i+1,end,dp);
			count+=val;
		}	
		return dp[dif]=count;
	}
}
int BUCB(int n){//bottomup
	int start,end;
	vector<int> dp(n+1,-1);
	dp[0]=1;
	dp[1]=1;
	for(int j=1;j<=n;j++){
		start=1;
		end =j;
		
	int count=0;
	for(int i=start;i<=end;i++){
		int val = dp[(i-1)-start+1]*dp[end-(i+1)+1];
		count+=val;
	}
	dp[end-start+1]=count;	
	}
	cout<<"\nBUCB\n";
		for(auto x:dp){
		cout<<x<<" ";
	}
	return dp[n];
}
int main(){
	int n=4;
	vector<int> dp (n+1,-1);
	
	dp[0]=1;
	dp[1]=1;
	cout<<countBST(1,n,dp);
	for(auto x:dp){
		cout<<x<<" ";
	}
	cout<<BUCB(n);
}
