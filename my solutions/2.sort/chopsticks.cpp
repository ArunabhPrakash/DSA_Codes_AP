#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;//not yet handling duplicate values
int pairSticksHelper(int n,vector<int> &length,int D,unordered_set<int> &mappy,unordered_map<string,int> &dp){
	if(n<0){
		return 0;
	}
	else{
	string state;
	for (auto i = mappy.begin(); i != mappy.end(); ++i) {
    int val = *i;
	state+=to_string(val);	
	}
	state+=to_string(n);	
	if(dp.find(state)!=dp.end()){
		return dp[state];
	}
	if(mappy.find(length[n])==mappy.end()){
		mappy.insert(length[n]);
		int maxincp=INT_MIN;
		int maxncp=INT_MIN;
		
		for(int j=0;j<length.size();j++){
			if(mappy.find(length[j])==mappy.end()){
				int val = abs(length[n]-length[j]);
				if(val<=D){
					mappy.insert(length[j]);
					int curr=1+pairSticksHelper(n-1,length,D,mappy,dp);
					maxincp=max(curr,maxincp);
					mappy.erase(length[j]);
				}
			}
			
		}

		mappy.erase(length[n]);
		maxncp = pairSticksHelper(n-1,length,D,mappy,dp);
		dp[state]=max(maxincp,maxncp);
		return dp[state];	
	}
	else{
		dp[state]=pairSticksHelper(n-1,length,D,mappy,dp);
		return dp[state];
	}	
	}
	
	
}
int pairSticks(vector<int> &length, int D)
{
	unordered_set<int> mappy;
	int n=length.size()-1;
	unordered_map<string,int> dp;
	return pairSticksHelper(n,length,D,mappy,dp);
}

int main(){
	vector<int> length  = {1,2,3,4,5,6,7,8};
	int D =2;
	cout<<pairSticks(length,D);
}
