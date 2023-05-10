#include<iostream>
#include<vector>
using namespace std;



int cntSubarrays(vector<int> arr,int k){
	int count=0;
	for(int i=0;i<arr.size();i++){
		int sum=arr[i];
		if(sum==k){
			count++;
		}
		for(int j=i+1;j<arr.size();j++){
			sum+=arr[j];
			if(sum==k){
				count++;
			}
			
		}
	}
	return count;
}

int main(){
	vector<int> arr={10,2,-2,-20,10};
	int k=-10;
	cout<<cntSubarrays(arr,k);
}
