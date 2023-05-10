#include<iostream>
#include<vector>
using namespace std;
int countWays(int n,int k){
	if(n==0){
		return 1;//base case 1
	}
	if(n<0){
		return 0;//base case 2
	}
	//recursive case
	int ans=0;
	for(int jump = 1;jump<=k;jump++){
		ans += countWays(n-jump,k);
	}
	return ans;
	
}
//top down
int countWaysTD(int n,int k,int *dp){// top down
	if(n==0){
		return 1;//base case 1
	}
	if(n<0){
		return 0;//base case 2
	}
	//check if state is already computed
	if(dp[n]!=0){
		return dp[n];
	}
	//recursive case
	int ans=0;
	for(int jump = 1;jump<=k;jump++){
		ans += countWaysTD(n-jump,k,dp);
	}
	return dp[n]=ans;
	
}

int countWaysBU(int n,int k){
	//iterative 
	vector<int> dp(n+1,0);
	dp[0]=1;
	
	for(int i=1;i<=n;i++){
		for(int jump=1; jump<=k; jump++){
			if(i-jump>=0){
				dp[i] += dp[i-jump];
			}
		}
	}
	return dp[n];
}
//BU optimised
int countWaysBUOpt(int n,int k){
	//iterative 
	vector<int> dp(n+1,0);
	dp[0]=dp[1]=1;
	for(int i=2;i<=k;i++){
		dp[i] = 2*dp[i-1];
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=2*dp[i-1]-dp[i-k-1];
	}
	return dp[n];
}
int main(){
	int n,k;
	cin>>n>>k;
	int dp[1000] = {0};
	cout<<countWaysTD(n,k,dp)<<endl;
	cout<<countWaysBU(n,k)<<endl;
	cout<<countWaysBUOpt(n,k)<<endl;
	return 0;
}
