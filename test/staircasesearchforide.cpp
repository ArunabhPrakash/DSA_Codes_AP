#include<iostream>
#include<vector>
using namespace std;

pair<int,int> staircaseSearch(int m,int n,vector<vector<int>> v,int k){
	pair<int,int> coords;
	coords.first=-1;
	coords.second=-1;
	int i=0;
	int j=n-1;
	while(i<m and j>=0){
		if(k==v[i][j]){
			coords.first=i;
			coords.second=j;
			return coords;
		}
		else if(k>v[i][j]){
			i++;
		}
		else{
			j--;
		}
	}
	return coords;	
}

int main(){
	vector<vector<int>> arr={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
	int n=4,m=4;
	pair<int,int> coords = staircaseSearch(m,n,arr,50);
	cout<<coords.first<<" "<<coords.second<<endl;
	return 0;
}
