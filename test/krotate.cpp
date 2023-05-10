#include<iostream>
#include<vector>
using namespace std;

void rotatefunc(vector<int> &arr,int k){

	int t1,t2;
	
	for(int i=1;i<=k;i++){
		t1=arr[0];
		for(int j=0;j<arr.size();j++){
			
			if(j==arr.size()-1){
				arr[0]=t1;
			}
			else{
			t2=arr[j+1];
			arr[j+1]=t1;
			t1=t2;
			
			}
			
		}
	}
		for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	vector<int> arr ={1,2,3,4,5};
	int k;
	cin>>k;
	rotatefunc(arr,k);

	
}
