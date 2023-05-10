#include<iostream>
using namespace std;


int earthLevel(int k)
{
	int count=0;
	while(k!=0){
		int val=1;
	    while(val<=k){
	    	val=val*2;
	    
		}
		
		k=k-(val/2);
		count++;
		
	}
	return count;
}

int main(){
	int k=7;
	cout<<earthLevel(k);
}
