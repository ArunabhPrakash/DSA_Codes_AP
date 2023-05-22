#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool compare(pair<int,int> &a,
              pair<int,int> &b)
{
    return (a.second < b.second);
}
int defkin(int W, int H, vector<pair<int, int>> &position)
{
    position.push_back({W,H});
    vector<pair<int,int>> ypos = position;
    sort(position.begin(),position.end());
    sort(ypos.begin(),ypos.end(),compare);
    int xstart=0;
    int ystart=0;
    int maxblocks=INT_MIN;
    for(int i=0;i<position.size();i++){
        int xsize = position[i].first-xstart-1;
        for(int j=0;j<ypos.size();j++){
            int ysize = ypos[i].second-ystart-1;
            int blocks = xsize*ysize;
            maxblocks=max(maxblocks,blocks);
            ystart=ypos[i].second;
            
        }
        xstart=position[i].first;
    }
    return maxblocks;
    
}

int main(){
	vector<pair<int,int>> position = {{3,8},{11,2},{8,6}};
	cout<<defkin(15,8,position);
}
