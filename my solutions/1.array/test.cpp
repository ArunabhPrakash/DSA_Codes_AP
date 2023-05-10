#include<iostream>
#include<vector>
using namespace std;

int findClosest(vector<int> &arr,int val,int start,int end,int closest,int sentVal){
    if(start>end){
        return closest;
    }
    else{
        int mid = (start +end)/2;
        if((abs(val -arr[mid]))<(abs(val-arr[closest] and arr[mid]!=sentVal))){
            closest = mid;
        }
        if(arr[mid] == val){
            return closest;
        }
        else if(val<arr[mid]){
            return (arr,val,start,mid-1,closest,sentVal);
        }
        else{
            return (arr,val,mid+1,end,closest,sentVal);
        }
    }
}
pair<int, int> closestSum(vector<int> arr, int x){
    pair<int,int> finclosest;
    finclosest.first = arr[0];
    finclosest.second = arr[1];
    for(int i=0;i<arr.size();i++){
        int end = arr.size()-1;
        int mid = (0+ end)/2;
        int val = x-arr[i];
        int closest =findClosest(arr,val,0,end,mid,arr[i]);
        if(abs(x-(arr[i]+arr[closest]))<abs(x-(finclosest.first+finclosest.second))){
            finclosest.first = arr[i];
            finclosest.second = arr[closest];
        }
    }
    return finclosest;
}

