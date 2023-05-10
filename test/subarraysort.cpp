#include<iostream>
#include<vector>
using namespace std;
vector<int> subarraysort(vector<int> arr){
	int n=arr.size();
	int start=-1;
	int end=-1;
	vector<int> result;
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1] or arr[i]<arr[mark]){
			if(start==-1){
				start=i;
				end=i+1;
			}
			else{
				end=i+1;
			}
		}
	}
	result.push_back(start);
	result.push_back(end);
	return result;
}
int main(){
	vector<int> arr={1,2,3,4,5,8,6,7,9,10,11};
	vector<int> result;
	result=subarraysort(arr);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
		
	}
}
