#include<iostream>
#include<vector>
using namespace std;

int basketball_select(vector<int> &a,vector<int> &b,int n,int r){
	if(n<0){
		return 0;
	}
	else{

		if(r==0){
			int excr0=basketball_select(a,b,n-1,2);
			int excr1=b[n]+basketball_select(a,b,n-1,1);
			return max(excr0,excr1);
		}
		else if(r==1){
			int excr0=a[n]+basketball_select(a,b,n-1,0);
			int excr1=basketball_select(a,b,n-1,2);
			return max(excr0,excr1);
		}
		else{
			int excr0=a[n]+basketball_select(a,b,n-1,0);
			int excr1=b[n]+basketball_select(a,b,n-1,1);
			return max(excr0,excr1);
		}
	}
}
int main(){
	vector<int> a = {1,4,5};
	vector<int> b = {3,7,9};
	cout<<basketball_select(a,b,2,2);
}
