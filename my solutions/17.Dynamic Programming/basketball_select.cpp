#include<iostream>
#include<vector>
using namespace std;

int basketball_select(vector<int> &a,vector<int> &b,int n,int r,vector<vector<int>> &dp){
	if(n<0){
		return 0;
	}
	else{
		if(dp[n][r]!=-1){
			return dp[n][r];
		}
		else{
		if(r==0){
			int excr0=basketball_select(a,b,n-1,2,dp);
			int excr1=b[n]+basketball_select(a,b,n-1,1,dp);
			return dp[n][r]=max(excr0,excr1);
		}
		else if(r==1){
			int excr0=a[n]+basketball_select(a,b,n-1,0,dp);
			int excr1=basketball_select(a,b,n-1,2,dp);
			return dp[n][r]=max(excr0,excr1);
		}
		else{
			int excr0=a[n]+basketball_select(a,b,n-1,0,dp);
			int excr1=b[n]+basketball_select(a,b,n-1,1,dp);
			int noselect = basketball_select(a,b,n-1,2,dp);
			return dp[n][r]=max(noselect,max(excr0,excr1));
		}	
		}
		
	}
}
int main(){
	vector<int> a = {1,2,9};
	vector<int> b = {10,1,1};
	vector<vector<int>> dp(3, vector<int> (a.size(), -1)); 
	cout<<basketball_select(a,b,2,2,dp);
}
