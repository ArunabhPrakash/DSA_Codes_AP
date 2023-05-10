#include<iostream>
using namespace std;
 
 
int power(long int x, unsigned int y, int mod)
{
	unsigned int ans=1;
    while(y!=0){
    	if(y&1){
    		ans=ans*x;
    		
		}
		x=x*x;
		y=y>>1;
	}
	ans=ans%mod;
	return ans;
    
}

int main(){
	int x=12;
	int y=25;
	int mod=10007;
	cout<<power(x,y,mod);
}
