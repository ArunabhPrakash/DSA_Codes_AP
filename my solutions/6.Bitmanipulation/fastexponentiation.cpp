#include<iostream>
using namespace std;

int fastExpo(int a,int n){
	int ans=1;
	while(n>0){
		int last_bit=(n&1);
		if(last_bit){
			ans = ans*a;
		}
		a=a*a;// like in case of 15, it is 1111, so 2^8 *2^4 * 2^2 * 2^1  
		n=n>>1;
	}
	return ans;
}

int main(){
	int a,n;
	cin>>a>>n;
	cout<<fastExpo(a,n)<<endl;
}
