#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    int suma=a.first+a.second;
    int sumb=b.first + b.second;
    return suma<sumb;
}
vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){
   sort(v.begin(),v.end(),compare);
   return v;
    
}
int main(){
	vector<pair<int,int>> arr = { {2,3},{1,2},{3,4},{2,4} ,{1,4} };
	arr = sortCabs(arr);
	for(pair<int,int> val:arr){
		cout<<val.first<<","<<val.second<<" ";
	}
}
