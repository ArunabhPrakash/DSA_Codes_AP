#include<iostream>
#include"maxh.h"
using namespace std;

int main(){
	MHeap ob;
	ob.push(1);
	ob.push(9);
	ob.push(22);
	ob.push(7);
	cout<<ob.top();
	ob.pop();
	cout<<ob.top();
}
