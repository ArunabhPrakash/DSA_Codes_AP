#include<bits/stdc++.h>
using namespace std;
bool compare(pair<string,int> a,pair<string,int> b){
    return a.second<b.second;
}
bool compare2(pair<string,int> a,pair<string,int> b){
    return a.first<b.first;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){
    if(S=="price"){
        sort(v.begin(),v.end(),compare);
    }
    else{
        sort(v.begin(),v.end(),compare2);
    }
    
    return v;
}
