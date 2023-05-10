#include<iostream>
#include"heap.h"
#include"maxh.h"
using namespace std;

int main(){
	int empage[10]={22,34,26,78,35,65,44,29,66,84};
	int size=10;
	MHeap maxH(size);
	Heap minH(size);
	
	for(int i=0;i<size;i++){
		maxH.push(empage[i]);
		minH.push(empage[i]);
	}
	cout<<"max element:"<<maxH.top();
	cout<<"\nmin element:"<<minH.top();
	
}
