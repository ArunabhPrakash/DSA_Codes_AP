#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int binsearch(vector<int> a2,int k,int s,int e){
	int close=0;
	if(s>e){
		return close;
	}
	else{
	int mid=(s+e)/2;
	if(a2[mid]==k){
		return mid;
	}
	else if(a2[mid]>k){
		close=mid;
		return (a2,k,s,mid-1);
	}	
	else{
		close=mid;
		return (a2,k,mid+1,e);
	}
	}
	
}
pair<int,int> minpair(vector<int> a1,vector<int> a2){
	pair<int,int> min;
	min.first=0;
	min.second=0;
	for(int i=0;i<a1.size();i++){
		int s=0;
		int e=a1.size()-1;
		int val=binsearch(a2,a1[i],s,e);
		
		
		int minc=a2[min.first]-a1[min.second];
		if(minc<0){
			minc=minc*(-1);
			
		}
		
		int valc=a2[val]-a1[i];
		if(valc<0){
			valc=valc*(-1);
			
		}
	
		if(valc<minc){
			min.first=i;
			min.second=val;
		}
	}
	return min;
	
}
int main(){
	vector<int> a1={-1,5,10,20,3};
	vector<int> a2={26,134,135,15,17};
	sort(a1.begin(),a1.end());
	sort(a2.begin(),a2.end());
	pair<int,int> min=minpair(a1,a2);
	cout<<a1[min.first]<<" "<<a2[min.second];
}
