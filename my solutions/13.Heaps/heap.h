#include<vector>
using namespace std;
//implemented min heap, to imple max , use compare func to call acc to heap
class Heap{
	
	vector<int>	v;
	
	void heapify(int i){
		
		int left = 2*i;
		int right = 2*i +1;
		
		int minIdx = i;
		if(left <v.size() and v[left]<v[i]){
			minIdx = left;
		}
		if(right<v.size() and v[right]<v[minIdx]){
			minIdx = right;
		}
		if(minIdx!=i){
			swap(v[i],v[minIdx]);
			heapify(minIdx);
		}
	}
public:
	Heap(int default_size=10){
		v.reserve(default_size);
		v.push_back(-1); //last element is size-1,to remove v[0]
	}
	void push(int data){
		v.push_back(data);
		int index = v.size()-1;
		int parent = index/2;
		
		while(index>1 and v[index] < v[parent]){
			swap(v[index],v[parent]);
			index = parent;
			parent = parent/2;
		}
	}
	int top(){
		return v[1];
	}
	void pop(){
		int idx = v.size()-1;
		swap(v[1],v[idx]);
		v.pop_back();
		heapify(1);
	}
	bool empty(){
		return v.size()==1;
	}
};
