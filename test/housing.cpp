#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> housing(vector<int> arr,int val){
	int i=0;
	int j=0;
	vector<pair<int,int>> result;
	int n=arr.size();
	int cs=arr[j];
	while(i<n and j<n){
		if(cs>val){
			cs-=arr[i];
			i++;
		
		}
		else if(cs<val){
			cs+=arr[j+1];
			j++;
			
		}
		else{
			result.push_back(make_pair(i,j));
			cs-=arr[i];
			i++;
		}
	}
	return result;
}
int main(){
	vector<int> arr={1,3,2,1,4,1,3,2,1,1,2};
	int val=8;
	vector<pair<int,int>> result;
	result=housing(arr,val);
	for(int i=0;i<result.size();i++){
		cout<<result[i].first<<","<<result[i].second<<endl;
	}
}
