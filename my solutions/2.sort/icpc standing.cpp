#include<iostream>
#include<vector>
#include<string>
using namespace std;

int badness(vector<pair<string,int>> &teams){
    int maxc=INT_MIN;
    int fcost = 0;
    
    vector<int> sortarr;
    for(int i=0;i<teams.size();i++){
        maxc= max(teams[i].second,maxc);
    }
    vector<int> countarr(maxc+1);
    for(int i=0;i<teams.size();i++){
        countarr[teams[i].second]++;
    }
    for(int i=0;i<=maxc;i++){
        while(countarr[i]!=0){
            sortarr.push_back(i);
            countarr[i]--;
        }
    }   
    for(int i=0;i<sortarr.size();i++){
        if(i!=sortarr[i]-1){
            int qcost = abs(sortarr[i]-(i+1));
            fcost = fcost+qcost;
        }
    }
    return fcost;
}

int main(){
	vector<pair<string,int>> teams;
	teams.push_back({"a",1});
	teams.push_back({"b",2});
	teams.push_back({"c",2});
	teams.push_back({"d",1});
	teams.push_back({"e",5});
	teams.push_back({"f",7});
	teams.push_back({"g",7});
	cout<<badness(teams);
	
}
