#include<iostream>
using namespace std;
int findinteger(int n,int s,int e){
	if(s>e){
		return -1;
	}
	else{
		int mid=(s+e)/2;
		int ans=0;
		if((mid*mid)==n){
			return mid;
		}
		else if((mid*mid)>n){
			return findinteger(n,s,mid-1);
		}
		else{
			ans=mid;
		
			ans=max(ans,findinteger(n,mid+1,e));
			return ans;
		}
		
	}
	
}
float squareroot(int n,int p){
	int s=0;
	int e=n;
	float val=findinteger(n,s,e);
	int divider=10;
	for(int i=0;i<p;i++){
		
		for(float j=1;j<=9;j++){
			float temp=val+(j/divider);
			
			float tempsq=temp*temp;
			if(tempsq<=n){
				val=temp;
				cout<<temp<<endl;
			}
		}
		divider=divider*10;
	}
	return val;
}
int main(){
	int n=21;
	int p=3;
	cout<<squareroot(n,p);
}
