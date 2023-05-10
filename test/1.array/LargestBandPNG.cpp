#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr){
	int n=arr.size();
	unordered_set<int> s;
	int largestLen=0;
	int cnt=0;
	for(int x:arr){
		s.insert(x);
	}
	for(auto element:s){
		int parent=element-1;
		if(s.find(parent)==s.end()){
			int next_no=element+1;
			int cnt=1;
			while(s.find(next_no)!=s.end()){
				next_no++;
				cnt++;
			}
			if(cnt>largestLen){
				largestLen=cnt;
			}
		}
	}
	return largestLen;
}
int main(){
	vector<int> arr{1,9,3,0,18,5,2,10,7,12,6};
	cout<<largestBand(arr);
	return 0;
}
