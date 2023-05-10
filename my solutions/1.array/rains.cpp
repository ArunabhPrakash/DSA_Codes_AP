#include<iostream>
#include<vector>
using namespace std;

int rains(vector<int> &arr){
	vector<int> left (arr.size());
	vector<int> right (arr.size());
	int maxh=INT_MIN;
	int maxtrap = 0;
	cout<<"\nleft side:\n";
	for(int i=0;i<arr.size();i++){
		maxh=max(arr[i],maxh);
		left[i]=maxh;
		cout<<left[i]<<" ";
	}
	maxh=INT_MIN;
	cout<<"\nrightside:\n";
	for(int i=arr.size()-1;i>=0;i--){
		maxh=max(maxh,arr[i]);
		right[i]=maxh;
		cout<<right[i]<<" ";
	}
	cout<<"\nTrap at each building\n";
	for(int i=0;i<arr.size();i++){
		maxtrap += min(left[i],right[i])-arr[i];
		
	}
	return maxtrap;
}
int main(){
	vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<rains(arr);
}
