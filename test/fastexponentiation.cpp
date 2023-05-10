#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int p;
	cin>>p;
	int ans=1;
	while(p!=0){
		if(p&1){
			ans=n*ans;
		}
		n=n*n;
		p=p>>1;
	}
	cout<<ans;
}
