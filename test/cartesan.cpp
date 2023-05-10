#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<pair<int,int>> arr={(3,4),(2,3),(3,7),(1,5),(3,4)};
	for(int i=0;i<arr.size();i++){
		cout<<arr[i].first<<arr[i].second;
	}
	
}
