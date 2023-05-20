#include<iostream>
#include<vector>
using namespace std;
//bottom up
int ninjaTraining(int n,vector<vector<int>> &points){
	    vector<vector<int>> dp(n,vector<int>(n,-1)); 
		dp[0][0]=points[0][0];
		dp[0][1]=points[0][1];
		dp[0][2]=points[0][2];
		for(int i=1;i<n;i++){
			for(int j=0;j<n;j++){
				int sum1=-1;
				int sum2=-1;
				int sum3=-1;
				if(j!=0){
					sum1=points[i][j]+dp[i-1][0];
				}
				if(j!=1){
					sum2=points[i][j]+dp[i-1][1];
				}
				if(j!=2){
					sum3=points[i][j]+dp[i-1][2];
				}
				dp[i][j]=max(sum1,max(sum2,sum3));
			}
		}

		return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

}
int main(){
	vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};
	cout<<ninjaTraining(3,points);
}
