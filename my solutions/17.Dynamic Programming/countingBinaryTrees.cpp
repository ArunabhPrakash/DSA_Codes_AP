#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countTrees(int n,vector<int> &dp){//binary trees,top down
	if(n==1 or n==0){
		return dp[n];
	}
	else{
		if(dp[n]!=-1){
	
			return dp[n];
		}
	
		int count=0;
		int L=n-1;
		for(int R=0;R<n;R++){
			int val = countTrees(R,dp)*countTrees(L,dp);
			count+=val;
			L--;	
		}
		return dp[n]=count;
	}
}

int CTBU(int n){//bottomup
	vector<int> dp(n+1,-1);
	dp[0]=1;
	dp[1]=1;
	
	for(int i=2;i<=n;i++){
	int L=i-1;
	int count=0;
	for(int R=0;R<i;R++){
		int val = dp[L]*dp[R];
		count+=val;
		L--;
	}
	dp[i]=count;	
	}
	cout<<"\n";
	for(auto x:dp){
		cout<<x<<" ";
		
	}
	cout<<"\n";
	return dp[n];
}
int main(){
	int n=6;
	vector<int> dp (n+1,-1);
	dp[0]=1;
	dp[1]=1;
	cout<<countTrees(n,dp);
	cout<<"\n";
	for(auto x:dp){
		cout<<x<<" ";
	}
	cout<<"\n"<<CTBU(n);
}
