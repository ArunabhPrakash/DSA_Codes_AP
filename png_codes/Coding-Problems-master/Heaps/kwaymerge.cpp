#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arrays){
	int k=arrays.size();
	//triplet - element,array idx, element idx
	priority_queue <vector<int>,vector<vector<int>>, greater<vector<int>>> q;
	
	vector<int> output;
	
	for(int i=0;i<k;i++){
		int element = arrays[i][0];
		q.push({element,i,0});
	}
	//start popping and pushing more elemnts
	while(!q.empty()){
		auto top = q.top();
		q.pop();
		
		int element = top[0];//value at that index in that array
		int a_idx=top[1];//array index
		int e_idx= top[2];//element index
		
		output.push_back(element);
		if(e_idx+1<arrays[a_idx].size()){
			int next_element = arrays[a_idx][e_idx+1];
			q.push({next_element,a_idx,e_idx+1});
		}
		
		
	}
	return output;
}
int main(){
	vector <vector<int> > arr = {{10,15,20,30},{2,5,8,14,24},{0,11,60,90}};
	vector<int> result = mergeKArrays(arr);
	
	for(auto x:result){
		cout<<x<<" ";
	}
}
