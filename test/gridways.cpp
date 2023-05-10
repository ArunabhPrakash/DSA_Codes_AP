#include<iostream>
using namespace std;
int gridways(int m,int n,int x,int y){
	if(x==m-1 and y==n-1){
		return 1;
	}
	else if(x<m-1 and y<n-1){
		return gridways(m,n,x+1,y)+gridways(m,n,x,y+1);
		
	}
	else if(x<m-1 and y==n-1){
		return gridways(m,n,x+1,y);
	}
	else if(x==m-1 and y<n-1){
		return gridways(m,n,x,y+1);
	}
	else{
		return 0;
	}
}
int main(){
	int m;
	int n;
	cin>>m>>n;
	cout<<gridways(m,n,0,0);
}
