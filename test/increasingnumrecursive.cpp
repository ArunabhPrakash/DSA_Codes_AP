#include<iostream>
#include<vector>
using namespace std;
vector<int> callno(int n,int N,vector<int> result){
	if(n<=N){
		result.push_back(n);
		result=callno(n+1,N,result);
	}
	return result;
}
vector<int> increasingNumbers(int N) {
    vector<int> result;
	result=callno(1,N,result);
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<int> result;
	result=increasingNumbers(n);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}
