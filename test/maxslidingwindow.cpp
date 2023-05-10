#include<iostream>
#include<vector>
#include<climits>
using namespace std;


vector<int> maxInWindow(vector<int> input,int k){
    vector<int> output;
	int i=0;
	for(int j=0;j<input.size();j++){
    	if(j-i+1==k){
    		int maxv=INT_MIN;
    		for(int z=i;z<=j;z++){
    			maxv=max(maxv,input[z]);
			}
			output.push_back(maxv);
			i++;
		}
	}
	return output;
}

int main(){
	vector<int> arr={1,2,3,1,4,5,2,3,6};
	vector<int> output;
	int k=3;
	output=maxInWindow(arr,k);
	for(int i=0;i<output.size();i++){
		cout<<output[i]<<" ";
	}
}
