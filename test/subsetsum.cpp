#include<iostream>
#include<vector>
using namespace std;

bool ifsubsetSum(int val,vector<int> num,int j){
	cout<<val<<" :"<<j<<endl;
	if(val==0){
		return true;
	}
	else if(val<0 or j==num.size()){
		return false;
	}
	else{
		if(ifsubsetSum(val-num[j],num,j+1)==true or ifsubsetSum(val,num,j+1)==true){
			return true;
		}
		else{
			return false;
		}
	}
}

vector<bool> subsetSum(vector<int> num, vector<int> query)
{
	int size=query.size();
	vector<bool> result(size,false);
	for(int i=0;i<size;i++){
		int j=0;
		if(ifsubsetSum(query[i],num,j)){
			result[i]=true;
		}
	}
	return result;
}

int main(){
	vector<int> num={1,2,3};
	vector<int> query={5,3,8};
	vector<bool> result;
	result=subsetSum(num,query);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}
