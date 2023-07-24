#include<iostream>
#include<vector>
using namespace std;

int cutRod(vector<int> &rod,int size,vector<int> &dp){//top down
	if(size==0){
		return dp[0];
	}
	else{
		if(dp[size]!=-1){
			return dp[size];
		}
		int finalVal=INT_MIN;
		for(int i=0;i<size;i++){
			finalVal = max(finalVal,rod[i]+cutRod(rod,size-(i+1),dp));
		}
		return dp[size]=finalVal;
	}
}
int BUCR(vector<int> &rod,int size){//bottomup
	vector<int> dp(size+1,-1);
	dp[0]=0;
	for(int i=1;i<=size;i++){
		for(int j=0;j<i;j++){
			dp[i]=max(dp[i],rod[j]+dp[i-(j+1)]);
		}
	}
		for(auto x: dp){
		cout<<x<<" ";
	}
	return dp[size];
}
int main(){
	vector<int> rod = {1,5,8,9,10,17,17,20};
	vector<int> dp (rod.size()+1,-1);
	dp[0]=0;
	cout<<cutRod(rod,rod.size(),dp)<<"\n";
	
	for(auto x: dp){
		cout<<x<<" ";
	}
	cout<<"\n"<<BUCR(rod,rod.size());
}
