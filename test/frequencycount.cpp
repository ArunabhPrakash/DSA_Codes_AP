#include<iostream>
#include<vector>
using namespace std;
int frequencycount(vector<int> arr,int k,int s,int e){
	if(s>e){
		return -1;
	}
	else{
		
		int mid=(s+e)/2;
		int midr=mid+1;
		int midl=mid-1;
		int count=0;
		if(arr[mid]==k){
			count++;
			while(arr[midl]==k){
				count++;
				midl--;
			}
			while(arr[midr]==k){
				count++;
				midr++;
			}
		return count;
		}
		else if(arr[mid]>k){
			return frequencycount(arr,k,s,mid-1);
		}
		else{
			return frequencycount(arr,k,mid+1,e);
		}
			
	}
}
int main(){
	vector<int> arr={0,1,1,1,1,2,2,2,3,4,4,5,10};
	int k=2;
	int s=0;
	int e=arr.size()-1;
	cout<<frequencycount(arr,k,s,e);
}
