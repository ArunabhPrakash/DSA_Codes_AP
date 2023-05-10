#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> twod;
	
	int t;
	for(int i=0;i<2;i++){
		vector<int> oned;
		for(int j=0;j<5;j++){
			cin>>t;
			oned.push_back(t);
		}
		twod.push_back(oned);
		
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<5;j++){
			cout<<twod[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
