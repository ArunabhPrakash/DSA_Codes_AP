#include<iostream>
#include<vector>
using namespace std;
//topdown
int wines (int dp[][10],int prices[],int L,int R,int y){
	if(L>R){
		return 0;
	}
	if(dp[L][R]!=0){//this causes dp instead of naive approach
		return dp[L][R];
	}
	int pick_left=y*prices[L] +wines(dp,prices,L+1,R,y+1);
	int pick_right = y*prices[R] + wines(dp,prices,L,R-1,y+1);
	return dp[L][R]=max(pick_right,pick_left);	 //so will finally return val dp[0][n-1]: will store final val
	
}

int wines_bottom_up(int prices[],int N){
	vector<vector<int>> dp(N+1,vector<int>(N+1,0));//here time is N^2 and 2dvector is square-depics bottles sold from both sides
 	for(int i=N-1;i>=0;i--){
		for(int j=0;j<N;j++){//loop starts with last row first item and ends at first row last item
			if(i==j){
				dp[i][i]=N*prices[i];//wherever i,i means element was sold in last year
			}
			else if(i<j){//means right side of the curve formed by diagonal(i,i)
				int y=N-(j-i);//this will give year in which that bottle was selected
				int pick_left=prices[i]*y +dp[i+1][j];//if select left then add with same column next row
				int pick_right=prices[j]*y +dp[i][j-1];//if select right then add with same row previous column
				dp[i][j]=max(pick_left,pick_right);//then you choose between bottom and left blocks:
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}
	return dp[0][N-1];
}

int main(){
	int a[]={2,3,5,1,4};
	int n =5;
	int dp[10][10]={0};//all val of dp is 0
	cout<<wines(dp,a,0,n-1,1)<<endl;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
			
		}
		cout<<endl;
	}
	wines_bottom_up(a,n);

}

