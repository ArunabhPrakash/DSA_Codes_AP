#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}


vector<pair<int, int>> sortCartesian(vector<pair<int, int>> &v)
{
    sort(v.begin(),v.end(),compare);
    return v;
    
}
int main(){
	vector<pair<int,int>> v = {{1,2},{2,3},{1,4}};
	sortCartesian(v);
	for(auto a:v){
		cout<<a.first<<","<<a.second<<" ";
	}
}
