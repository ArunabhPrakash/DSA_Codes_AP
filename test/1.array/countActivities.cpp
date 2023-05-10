#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool compare(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}


int countActivities(vector<pair<int,int> > v){
    //Complete this method
    
    sort(v.begin(),v.end(),compare);
    int count = 1;
    int finish = v[0].second;
    
    for(int i=1;i<v.size();i++){
        if(v[i].first>=finish){
            count++;
            finish = v[i].second;
        }
    }
    return count;
}

int main(){
	int arr[] = {7,0,4,8,4,5};
    int arr1[] = {9,10,5,9,10,7};
    int n = sizeof(arr)/sizeof(int);
    vector< pair <int,int> > vect;
      for (int i=0; i<n; i++){
      	 vect.push_back( make_pair(arr[i],arr1[i]) );
	  }
	  cout<<countActivities(vect);
	  
       
}
