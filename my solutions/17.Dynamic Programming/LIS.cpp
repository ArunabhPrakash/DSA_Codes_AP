#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int> arr){//total time taken is  n(n-1)/2 = o(n^2)
	int n= arr.size();
	vector<int> dp(n,1);//min all sequence is 1 including itself
	int len=1;
	
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp[i] = max(dp[i],1+dp[j]);
				len=max(len,dp[i]);
			}
		}
	}
	return len;
}

int main(){
	vector<int> arr{50,4,10,8,30,100};
	cout<<lis(arr)<<endl;
	return 0;
}
