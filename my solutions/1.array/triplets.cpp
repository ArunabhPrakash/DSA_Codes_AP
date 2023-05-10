#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
void triplets(vector<int> &arr,int sum){
	unordered_map <int,int> m;
	int size = arr.size();
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++){
		m[arr[i]]=i;
	}
	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++){
			int t = sum - arr[i] - arr[j];
			if(t>arr[j] && m.count(t)!=0){
				cout<<"\npair "<<arr[i]<<" "<<arr[j]<<" "<<arr[m[t]];
			}
		}
	}
}
int main(){
	vector<int> arr={1,2,3,4,5,6,7,8,9,15};
	int sum=18 ;
	triplets(arr,sum);
	
}
