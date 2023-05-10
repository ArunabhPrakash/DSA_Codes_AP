#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int solve(string str,vector<string> &dictionary,int i,int j){
	int sum=0;
	if(str[i]=='\0'){
		sum=1;
	}
	else{
		if(j==dictionary.size()){
			sum=0;
		}
		else{
			string temp=dictionary[j];
			int k;
			for(k=0;k<temp.size();k++){
				if(temp[k]!=str[i]){
					i=i-k;
					break;
				}
				i++;
			}
			if(k==temp.size()){

				sum+=solve(str,dictionary,i,j+1);
				
				i=i-k;
			}

			sum+=solve(str,dictionary,i,j+1);
			
		}
	}
	return sum;
}
int wordBreak(string str, vector<string> &dictionary){
	return solve(str,dictionary,0,0);
}

int main(){
	string str="ilikesamsungmobile";
	vector<string> dictionary={"i","like","sam","sung","samsung","mobile"};
	cout<<wordBreak(str,dictionary);
}
