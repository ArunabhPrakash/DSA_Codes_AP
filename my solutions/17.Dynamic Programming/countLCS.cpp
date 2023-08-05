#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countSubseq(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){//topdown
	
	if(j==s2.size()){
		return 1;
	}
	else if(i==s1.size()){
		return 0;
	}
	else{
	if(dp[j][i]!=-1){
		return dp[j][i];
	}
	else{
	
	if(s1[i]!=s2[j]){
		return dp[j][i]=countSubseq(s1,s2,i+1,j,dp);
	}
	else{
		int count=0;
		count+=countSubseq(s1,s2,i,j+1,dp);
		count+=countSubseq(s1,s2,i+1,j,dp);
		return dp[j][i]=count;
	}	
	}	
	}
	
}



int main(){
	string s1= "ABCDCE";
	string s2="ABC";
	vector<vector<int>> dp(s2.size(),vector<int> (s1.size(),-1));
	cout<<countSubseq(s1,s2,0,0,dp);
	for(auto x:dp){
		cout<<"\n";
		for(auto y:x){
			cout<<y<<" ";
		}
	}
}
