#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int,int> &a,pair<int,int> &b){
	return	a.second < b.second;
}
int busyLife(vector<pair<int,int>> &arr){
	sort(arr.begin(),arr.end(),compare);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i].first<<","<<arr[i].second<<" ";
	}
	int lastfirst=arr[0].first;
	int lastsec=arr[0].second;
	cout<<"\n"<<arr[0].first<<","<<arr[0].second<<" ";
	int count=1;
	for(int i=1;i<arr.size();i++){
		if(arr[i].first>=lastsec){
			count++;
			cout<<arr[i].first<<","<<arr[i].second<<" ";
			lastfirst = arr[i].first;
			lastsec = arr[i].second;
		}
	}
	return count;
}
int main(){
	vector<pair<int,int>> arr = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
	cout<<busyLife(arr);
	
}
