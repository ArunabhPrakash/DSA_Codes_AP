#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwaps(vector<int> &arr){
	vector<pair<int,int>> store (arr.size());
	for(int i=0;i<arr.size();i++){
		store[i].first=arr[i];
		store[i].second = i;
	}
	sort(store.begin(),store.end());//correct till here
	bool visited[arr.size()] = {false};
	int ans=0;
	int cycle=0;
	for(int i=0;i<store.size();i++){
		if(visited[i]==1 or store[i].second == i){
			continue;
		}
		else{
			int node = i;
			while(!visited[node]){
			int nextnode = store[node].second;
			visited[node]=true;
			node=nextnode;
			cycle+=1;
				
			}
			ans +=(cycle-1);
			cycle=0;
		}
	}
	return ans;
}
int main(){
	vector<int> arr={10,11,5,4,3,2,1};
	cout<<minSwaps(arr);
}
