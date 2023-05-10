#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

vector<string> formStrings(int i,int n,string result,vector<string> ans){
	if(i==n){
		ans.push_back(result);
		return ans;
	}
	else{
		if(result[i-1]=='0'){
			result+="0";
			ans=formStrings(i+1,n,result,ans);
			result[i]='1';
			ans=formStrings(i+1,n,result,ans);
		}
		else{
			result+="0";
			ans=formStrings(i+1,n,result,ans);
		}
		return ans;
	}
	
}
vector<string> binaryStrings(int n){
	vector<string> ans;
	string str="0";
	ans=formStrings(1,n,str,ans);
	str="1";
	ans=formStrings(1,n,str,ans);
	return ans;
}

int main(){
	int n=3;
	vector<string> ans;
	ans=binaryStrings(n);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}
