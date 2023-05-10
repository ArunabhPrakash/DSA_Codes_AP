#include<iostream>
#include<vector>
using namespace std;
void arrayfill(vector<int> arr,int i,int n,int val){
		if(i==n){
			cout<<endl;
			return;
		}
		arr.push_back(val);
		cout<<arr[i]<<" ";
		arrayfill(arr,i+1,n,val+1);
		arr[i]=0-arr[i];
		cout<<arr[i]<<" ";
		return;
		
	
}
int main(){
	vector<int> arr;
	int n;
	cin>>n;
	arrayfill(arr,0,n,1);
}
