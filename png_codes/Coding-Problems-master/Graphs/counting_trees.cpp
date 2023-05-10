#include<iostream>
#include<vector>
using namespace std;


int countBST(int n){
	if(n==0 or n==1){//nodes 1 or 0 only 1 way to arrange
		return 1;
	}
	int ans =0;
	for(int i=1;i<=n;i++){
		int x = countBST(i-1);
		int y = countBST(n-i);
		ans+= x*y;
	}
return ans;
}
// dp top down
int countBSTTD(int n,vector<int> dp){
	if(n==0 or n==1){//nodes 1 or 0 only 1 way to arrange
		return 1;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	int ans =0;
	for(int i=1;i<=n;i++){
		int x = countBSTTD(i-1,dp);
		int y = countBSTTD(n-i,dp);
		ans+= x*y;
	}
return dp[n]=ans;
}

//dp bottom up
int countBSTBU(int n){
	vector<int> dp(n+1,0);
	
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i] += (dp[j-1]*dp[i-j]);
		}
	}
	return dp[n];
}

int main(){
	int n=5;
	vector<int> dp(n+1,0);
	cout<<countBST(n)<<endl;
	cout<<countBSTTD(n,dp)<<endl;
	cout<<countBSTBU(n)<<endl;
	return 0;
}
