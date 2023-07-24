#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int frogjump(vector<int> &arr,int n,vector<int> &dp){
	if(n==arr.size()-1){
		return dp[n];
	}
	else{
		int jp1=INT_MAX;
		int jp2=INT_MAX;
		if(n+1<=arr.size()-1){
			jp1 = abs(arr[n]-arr[n+1]) + frogjump(arr,n+1,dp);
		}
		if(n+2<=arr.size()-1){
			jp2 = abs(arr[n]-arr[n+2]) + frogjump(arr,n+2,dp);
		}
		return dp[n]=min(jp1,jp2);
	}
}

int BUFJ(vector<int> &arr){
	vector<int> dp (arr.size(),-1);
	dp[arr.size()-1]=0;

	for(int i=arr.size()-2;i>=0;i--){
		int jp2 = INT_MAX;
		int jp1=INT_MAX;
		if(i+1<=arr.size()-1){
			jp1=abs(arr[i]-arr[i+1])+dp[i+1];
		}
		if(i+2<=arr.size()-1){
			jp2 = abs(arr[i]-arr[i+2])+dp[i+2];
		}
		dp[i]=min(jp1,jp2);
	}
	cout<<"\n";
		for(auto x:dp){
		cout<<x<<" ";
	}
	return dp[0];
}
int main(){
	vector<int> arr  = {30,10,60,10,60,50};
	vector<int> dp (arr.size(),-1);
	dp[arr.size()-1]=0;
	cout<<frogjump(arr,0,dp)<<"\n";
	for(auto x:dp){
		cout<<x<<" ";
	}
	cout<<"\n"<<BUFJ(arr);
}
