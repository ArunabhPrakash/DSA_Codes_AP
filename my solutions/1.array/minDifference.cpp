#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int searchHelper(vector<int> &arr,int val,int start,int end,int closest){
    if(start>end){
        return closest;
    }
    int mid = (start+end)/2;
    if((abs(val-arr[mid]))<(abs(val-arr[closest]))){
        closest = mid;
    }
    if(arr[mid]==val){
        return closest;
    }
    
    else if(val<arr[mid]){
        return searchHelper(arr,val,start,mid-1,closest);
    }
    else{
        return searchHelper(arr,val,mid+1,end,closest);
    }
}
pair<int,int> minDifference(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    pair<int,int> result;
    int calc=INT_MAX;
    for(int i=0;i<b.size();i++){
        int end = a.size()-1;
        int mid = (0+end)/2;
        int closest = searchHelper(a,b[i],0,end,mid);
        int closestcalc = abs(b[i]-a[closest]);
        if(closestcalc<calc){
            calc=closestcalc;
            result.first = a[closest];
            result.second = b[i];
        }
    }
    return result;
    
}
int main(){
	vector<int> a = {23,5,10,17,30};
	vector<int> b = {26,134,135,14,19};
	pair<int,int> result  = minDifference(a,b);
	cout<<result.first<<","<<result.second;
}
