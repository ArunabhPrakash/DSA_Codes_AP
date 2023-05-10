#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countMinSwaps(vector<int> arr){
	int n=arr.size();
	pair<int,int> ap[n];
	for(int i=0;i<n;i++){
		ap[i].first=arr[i];
		ap[i].second=i;
	}
	sort(ap,ap+n);
	vector<bool> visited(n,false);
	int ans=0;
	for(int i=0;i<n;i++){
		int old_position=ap[i].second;
		if(visited[i]==true or old_position==i){
			continue;
		}
		int node=i;
		int cycle=0;
		while(!visited[node]){
			visited[node]=true;
			int next_node = ap[node].second;
			node = next_node;
			cycle+=1;//cycle here counting nodes
		}
		ans+=(cycle-1);
	}
	return ans;
}

int main(){
	vector<int> arr{5,4,3,2,1};
	cout<<countMinSwaps(arr)<<endl;
	return 0;
}
