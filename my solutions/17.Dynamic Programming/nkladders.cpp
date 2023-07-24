#include<iostream>
#include<vector>
using namespace std;

int nkladders(int n,int k,vector<int> &dp){//topdown
	if(n==0){
		return dp[0];
	}
	else{
		if(dp[n]!=-1){
			return dp[n];
		}
		int count=0;
		for(int i=1;i<=k;i++){	
			if(i<=n){
				
				count+=nkladders(n-i,k,dp);
			}	
		}
		
		return dp[n]=count;
	}

}

int BUNK(int n,int k){//bottomup
	vector<int> dp(n+1,0);
	dp[0]=1;
	for(int i=0;i<dp.size();i++){
		for(int j=1;j<=k;j++){
			if(j<=i){
				dp[i]+=dp[i-j];
			}
		}
	}
	cout<<"\n";
	for(auto x: dp){
		cout<<x<<" ";
	}
	
	return dp[n];
}

int main(){
	int n=4;
	int k=3;
	vector<int> dp (n+1,-1);
	dp[0]=1;
	cout<<nkladders(n,k,dp);
	cout<<"\n"<<BUNK(n,k);
	
}
