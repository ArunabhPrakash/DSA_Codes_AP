#include<iostream>
using namespace std;

int ladderjump(int n){
	if(n==0){
		return 1;
	}
	else if(n>0){
		return ladderjump(n-1)+ladderjump(n-2)+ladderjump(n-3);
	}
	else{
		return 0;
	}
}

int main(){
	int n=4;
	cout<<ladderjump(n);
}
