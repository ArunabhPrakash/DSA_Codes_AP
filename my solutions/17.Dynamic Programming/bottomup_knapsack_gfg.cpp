int BUK(vector<int> &wts,vector<int> &vals,int w,int n){//bottomup also in original knapsack code

	vector<vector<int>> dp( wts.size(), vector<int> (w+1, 0));
	for(int i=0;i<wts.size();i++){
		for(int j=0;j<=w;j++){
			if(wts[i]<=j){
				if(i==0){
				dp[i][j]=max(dp[i][j],vals[i]);
				}
				else{
				dp[i][j]=max(max(dp[i][j],vals[i]+dp[i-1][j-wts[i]]),dp[i-1][j]);	
				}
				
			}
			else{
				if(i==0){
					dp[i][j]=0;
				}
				else{
				dp[i][j]=dp[i-1][j];	
				}
				
			}
		}
	}

	return dp[n][w];
}
int main(){
	vector<int> wts = {2,7,3,4};
	vector<int> val = {5,20,20,10};
	int w=11;
	cout<<BUK(wts,val,w,wts.size()-1);
}
