#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binary_search(int s,int e,vector<string> &a,string key){
	int mid;
	while(s<=e){
		mid = (s+e)/2;
		if(a[mid]==""){
			int i=mid-1;
			int j=mid+1;
			while(a[i]=="" and a[j]==""){
				i--;
				j++;
				if(i<0 and j>=a.size()){
					return -1;
				}
			}
			if(a[i]!=""){
				mid = i;
			}
			else{
				mid = j;
			}
		}
		
		if(a[mid]==key){
			return mid;
		}
		else if(key<a[mid]){
			e=mid-1;
		}
		else{

			s=mid+1;
		}
	}
	return -1;
}
int main(){
	vector<string> a = {"ai","","","bat","","","car","cat","","","dog"};
	int s=0;
	int e=a.size()-1;
	string k="bat";
	cout<<binary_search(s,e,a,k);
}
