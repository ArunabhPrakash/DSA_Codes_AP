#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    int N = v.size();
    sort(v.begin(),v.end());
    for(int i=0;i<N-1;i++){
    	if(v[i].first==v[i+1].first and v[i].second>v[i+1].second){
    		swap(v[i].second,v[i+1].second);
		}
	}
    return v;
}

int main(){
	vector<pair<int,int>> arr;
	int arrx[]={3,2,3,1,3};
	int arry[]={4,3,7,5,4};
	int n=sizeof(arrx)/sizeof(int);
	for(int i=0;i<n;i++){
		arr.push_back(make_pair(arrx[i],arry[i]));
	}
	arr=sortCartesian(arr);
	for(int i=0;i<n;i++){
		cout<<"("<<arr[i].first<<","<<arr[i].second<<")"<<" ";
	}
}
