#include<iostream>
using namespace std;

void generateBr(string output, int n,int open,int close,int i){
	if(i==2*n){
		cout<<output<<endl;
		return;
	}
	if(open<n){
		generateBr(output+"(",n,open+1,close,i+1);
	}
	if(close<open){
		generateBr(output+")",n,open,close+1,i+1);
	}
}
int main(){
	string output;
	int n;
	cin>>n;
	generateBr(output,n,0,0,0);
	
	return 0;
}
