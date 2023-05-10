#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arrayProd(vector<int> &arr){//tested
	vector<int> left(arr.size());
	vector<int> right(arr.size());
	vector<int> output(arr.size());
	for(int i=0;i<arr.size();i++){
		if(i==0){
			left[i]=1;
		}
		else{
			left[i]=arr[i-1]*left[i-1];
	
		}
	}
	for(int i=arr.size()-1;i>=0;i--){
		if(i==arr.size()-1){
			right[i]=1;
		}
		else{
			right[i]=right[i+1]*arr[i+1];
		}
	}
	for(int i=0;i<arr.size();i++){
		output[i]=left[i]*right[i];
	}
	return output;
}
int main(){
	vector<int> a = {1,2,3,4,5};
	vector<int> output = arrayProd(a);
	for(int a:output){
		cout<<a<<" ";
	}
}
