#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//running both here and in online compiler
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
int countActivities(vector<pair<int,int> > activities){
    for(int i=0;i<activities.size();i++){
    	cout<<activities[i].first<<","<<activities[i].second<<" ";
	}
	sort(activities.begin(),activities.end(),sortbysec);//callbackfunction
	cout<<"after sort\n";
	 for(int i=0;i<activities.size();i++){
    	cout<<activities[i].first<<","<<activities[i].second<<" ";
	}
    int count=1;
    pair<int,int> lastact;
    lastact.first=activities[0].first;
    lastact.second=activities[0].second;
    cout<<"\n"<<activities[0].first<<","<<activities[0].second<<" ";
    for(int i=1;i<activities.size();i++){
        if(activities[i].first>=lastact.second){
            count++;
            cout<<activities[i].first<<","<<activities[i].second<<" ";
            lastact.first=activities[i].first;
            lastact.second=activities[i].second;
        }
    }
    return count;
    
    
    
}

int main(){
	vector<pair<int,int>> arr = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};
	cout<<countActivities(arr);
}
