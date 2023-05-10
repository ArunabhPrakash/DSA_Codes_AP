#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	vector<int> a={10,5,2,0,7,6,4};
	int k=4;
	priority_queue<int,vector<int>, greater<int>> heap;
	for(int i=0;i<a.size();i++){
		heap.push(a[i]);
	}
	for(int i=1;i<k;i++){
		heap.pop();
	}
	cout<<heap.top();
	
}
