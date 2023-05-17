#include<iostream>
#include<vector>
using namespace std;

int findClosest(vector<int> &arr,int val,int start,int end,int closest,int sentVal){
	while(start<=end){
	int mid = (start+end)/2;
	int subsmid = abs(val-arr[mid]);
    int subsclosest = abs(val-arr[closest]);
	
	if (arr[mid]==val){
		return mid;
	}
	else if(arr[mid]>val){
		if(subsmid<subsclosest and arr[mid]!=sentVal){
            closest = mid;
        }
		end=mid-1;
	}
	
	else{
		if(subsmid<subsclosest and arr[mid]!=sentVal){
            closest = mid;
        }
		start=mid+1;
	}
	}	
	return closest;
}
pair<int, int> closestSum(vector<int> arr, int x){
    pair<int,int> finclosest;
    finclosest.first = arr[0];
    finclosest.second = arr[1];
    int findist = abs(x-(arr[0]+arr[1]));
    for(int i=0;i<arr.size();i++){
        int end = arr.size()-1;
        int mid = (0+ end)/2;
        int val = x-arr[i];
        int closest =findClosest(arr,val,0,end,mid,arr[i]);
        int distpair = abs(x-(arr[i] + arr[closest]));
        if(distpair<findist){
            finclosest.first = arr[i];
            finclosest.second = arr[closest];
            findist = distpair;
        }
        
    }
    return finclosest;
}
int main(){
	vector<int> arr = {10, 22, 28, 29, 30, 40};
	int x = 54;
	pair<int,int> ans = closestSum(arr,x);
	cout<<ans.first<<","<<ans.second;
}
