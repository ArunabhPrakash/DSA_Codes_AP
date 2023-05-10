#include<iostream>
using namespace std;

int RodCuttingDP(int *costs,int L)//dp bottom up
{
int dp[L+1];
dp[0] = 0;

for(int len=1;len<=L;len++){
    int ans = 0;
    for(int current_cut=1;current_cut<=len;current_cut++){// for each len, total cuts upto that len possible can be taken + dp of remaining(to take max of remaining val)
        ans = max(ans,costs[current_cut-1]+dp[len-current_cut]);
    }
    dp[len] = ans;

}

return dp[L];
}


//Lengths are assumed like 1,2,3,4....n.
int RodCuttingRecursive(int *costs,int L){
if(L==0){
    return 0;
}

int ans = 0;
//Make cuts of all possible lengths.
//Don't make a cut of length 0 that would not reduce our problem.
for(int cut_len = 1;cut_len<=L;cut_len++){

    int current_ans = costs[cut_len-1] + RodCuttingRecursive(costs,L-cut_len);//w/o dp sol
    ans = max(ans,current_ans);
}

return ans;
}
int RodCuttingRecursiveTD(int *costs,int L,int *dp){
if(L==0){
    return 0;
}
if(dp[L]!=0){
	
	return dp[L];
}
int ans = 0;
//Make cuts of all possible lengths.
//Don't make a cut of length 0 that would not reduce our problem.
for(int cut_len = 1;cut_len<=L;cut_len++){
	
    int current_ans = costs[cut_len-1] + RodCuttingRecursiveTD(costs,L-cut_len,dp);//w/o dp sol
    ans = max(ans,current_ans);
}

return dp[L]=ans;
}

int main(){


int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};//profit at each size, take cut size= index +1
int n = sizeof(arr)/sizeof(int);
int dp[n+1] = {0};

cout<<RodCuttingRecursive(arr,n)<<endl;
cout<<RodCuttingRecursiveTD(arr,n,dp)<<endl;
cout<<RodCuttingDP(arr,n)<<endl;

return 0;
}
