#include<iostream>
#include<queue>
using namespace std;

class Compare{//custom comparator, to be used alt to greater
	public:
		bool operator()(int a,int b){
			return a<b;
		}
};
int main(){
	int arr[]={10,15,20,13,6,90};
	int n = sizeof(arr)/sizeof(int);
	
	priority_queue<int> heap; // max heap by default, to reverse use vector<int> , greater int
	priority_queue<int,vector <int>,greater<int>> heap2;//min heap
	for(int x : arr){
		heap.push(x);//automatically heapify
		heap2.push(x);
		
	}
	cout<<"max heap\n";
	while(!heap.empty()){
		cout<<heap.top()<<endl;
		heap.pop();
	}
	cout<<"Min heap\n";
	while(!heap2.empty()){
		cout<<heap2.top()<<endl;
		heap2.pop();
	}
}
