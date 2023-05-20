#include<iostream>
#include<vector>
using namespace std;

int ninjaTrainingHelper(int n,vector<vector<int>> &points,int selected,vector<vector<int>> &dp){
	if(n==0){
		return 0;
	}
	else{
		if(dp[n][selected]!=-1){
		
			return dp[n][selected];
		}
		int sum1=-1;
		int sum2=-1;
		int sum3=-1;
		if(selected!=1){
			sum1=points[n-1][0]+ninjaTrainingHelper(n-1,points,1,dp);
		}
		if(selected!=2){
			sum2=points[n-1][1]+ninjaTrainingHelper(n-1,points,2,dp);
		}
		if(selected!=3){
			sum3=points[n-1][2]+ninjaTrainingHelper(n-1,points,3,dp);
		}
		
		dp[n][selected]=max(sum1,max(sum2,sum3));
		
		return dp[n][selected];
	}
}

int ninjaTraining(int n,vector<vector<int>> &points){
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); 
		return ninjaTrainingHelper(n,points,0,dp);

}

int main(){
	vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
	cout<<ninjaTraining(3,points);
}
