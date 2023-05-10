#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ten=1;
	int ans=0;
	while(n!=0){
		
		if(n&1){
			ans+=ten;
		}
		ten=ten*10;
		n=n>>1;
	}
	cout<<ans;
}
