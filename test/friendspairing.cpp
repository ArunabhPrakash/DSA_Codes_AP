#include<iostream>
using namespace std;

int friendsPairing(int n){
    int count=0;
	if(n<=-1){
    	return 0;
	}
	else{
		count=friendsPairing(n-1);
		count+=(n-1)*friendsPairing(n-2);
		return count;
	}
}
int main(){
	int n=3;
	cout<<friendsPairing(n);
}
