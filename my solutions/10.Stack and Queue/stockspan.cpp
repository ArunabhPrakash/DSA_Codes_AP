#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int prices[],int n,int span[]){//array by default calll by reference
	stack<int> s;//stack contains element idx (0,1,2,3,4..)
	s.push(0);
	span[0]=1;//span contains price span of each element
	for(int i=1;i<=n;i++){
		int currentPrices = prices[i];
		while(!s.empty() and prices[s.top()]<=currentPrices){
			s.pop();
		}
		if(!s.empty()){
			int prev_highest=s.top();
			span[i]=i-prev_highest;
		}
		else{
			span[i]=i+1;
		}
		s.push(i);
		
		
	}
}

int main(){
	int prices[]={100,80,60,70,60,75,85};
	int n = sizeof(prices)/sizeof(int);
	int span[100000] = {0};
	
	stockSpan(prices,n,span);
	for(int i=0;i<n;i++){
		cout<<span[i]<<" ";
	}
	return 0;
}
