#include<iostream>
using namespace std;

int nkladders(int n,int k){
	if(n==0){
		return 1;
	}
	else{
		int count=0;
		for(int i=1;i<=k;i++){	
			if(i<=n){
				count+=nkladders(n-i,k);
			}	
		}
		
		return count;
	}

}

int main(){
	int n=4;
	int k=3;
	cout<<nkladders(n,k);
	
}
