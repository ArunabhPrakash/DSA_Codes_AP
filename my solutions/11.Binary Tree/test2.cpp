#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
	list<pair<int,int>> arr {{1,2},{2,2},{3,2}};
	for(auto i:arr){
		cout<<i.first<<" "<<i.second<<endl;
	}
	unordered_map<int,pair<int,int>> m;
	m[1]={1,2};
	cout<<m[1].first<<" "<<m[1].second;
		map<int,pair<int,int>> m2;
	m2[1]={1,2};
	cout<<m2[1].first<<" "<<m2[1].second;
}
