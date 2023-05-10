#include<iostream>
#include<vector>
using namespace std;
  
int binsearch(vector<int> arr,int s,int e,int k){
	if(s>e){
		return -1;
	}
	else{
		int mid=(s+e)/2;
		if(arr[mid]==k){
			return mid;
		}
		else if(arr[mid]<k){
			cout<<mid<<":"<<arr[mid]<<endl;
			return binsearch(arr,mid+1,e,k);
		}
		else{
			cout<<mid<<":"<<arr[mid]<<endl;
			return binsearch(arr,s,mid-1,k);
		}
	}
}
int binarySearch(vector<int> v, int x)
{
	int s=0;
	int e=v.size()-1;
	return binsearch(v,s,e,x);
    
}

int main(){
	vector<int> arr={1,3,5,7,9};
	int k=;
	cout<<binarySearch(arr,k);
}
