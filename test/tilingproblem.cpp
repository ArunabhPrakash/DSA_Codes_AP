#include <iostream>
using namespace std;

int tillingProblem(int n, int m){
	int count=0;
	if(n<0){
		return 0;
	}
	else if(n==0){
		return 1;
	}
	else{
		
		count+=tillingProblem(n-1,m);
		count+=tillingProblem(n-m,m);
	}
	return count;
	
}

int main(){
	int N=4;
	int M=1;
	//cin>>N;
	//cin>>M;
	cout<<tillingProblem(N,M);
	
}
