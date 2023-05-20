#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){//workingin online compiler
    if(a.first!=b.first){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}


vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
    sort(v.begin(),v.end(),compare);
    return v;
    
}
