#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimumswaps(vector<int> arr){
	int n=arr.size();
	int swapc=0;
	vector<int> a=arr;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(arr[i]!=a[i]){
			for(int j=0;j<n;j++){
				if(a[j]==arr[i]){
					swap(a[i],a[j]);
					swapc++;
				}
			}
		}
	}
	return swapc;
}
int main(){
	vector<int> a1={10,11,5,4,3,2,1};
	cout<<minimumswaps(a1);
}
