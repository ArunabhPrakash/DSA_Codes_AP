#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int binsearch(vector<string> arr,string k,int s,int e){
	if(s>e){
		return -1;
	}
	int mid=(s+e)/2;
	int midr=mid+1;
	int midl=mid-1;
	if(arr[mid]==""){
		while(arr[midr]=="" and arr[midl]==""){
			midr++;
			midl--;
			if(midr>e and midl<s){
				return -1;
			}
		}
		if(arr[midr]!=""){
			mid=midr;
		}
		else{
			mid=midl;
		}
	}
	
	if(arr[mid]==k){
		return mid;
	}
	else if(arr[mid]<k){
		return binsearch(arr,k,mid+1,e);
	}
	else{
		return binsearch(arr,k,s,mid-1);
	}
	
}
int main(){
	vector<string> arr={"ai","","","bat","","","car","cat","","","dog"};
	string k = "ai";
	int s=0;
	int e=arr.size()-1;
	cout<<binsearch(arr,k,s,e);
}
