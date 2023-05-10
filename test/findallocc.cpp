#include<iostream>
#include<vector>
using namespace std;

vector<int> findall(int k,vector<int> v,int n,vector<int> result){
	if(n==v.size()){
		return result;
	}
	if(v[n]==k){
		result.push_back(n);
	}
	result=findall(k,v,n+1,result);
	return result;
}
vector<int> findAllOccurences(int k, vector<int> v){
    vector<int> result;
	result=findall(k,v,0,result);
	return result;
}

int main(){
	vector<int> arr={1,2,3,4,5,3,6,7,3};
	vector<int> result;
	int k=3;
	result=findAllOccurences(k,arr);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}
