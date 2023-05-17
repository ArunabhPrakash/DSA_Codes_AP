#include<iostream>
#include<vector>
using namespace std;

Count_sort(vector<int> &arr){
	int maxno=INT_MIN;
	for(int i=0;i<arr.size();i++){
		maxno = max(maxno,arr[i]);
	}

	vector<int> countarr(maxno+1,0);

	for(int i=0;i<arr.size();i++){
		countarr[arr[i]]++;
	}
	
	int j=0;
	for(int i=0;i<countarr.size();i++){
		
		while(countarr[i]>0){
			arr[j]=i;
			j++;
			countarr[i]--;
		}
	}
}
int main(){
	vector<int> arr = {6,5,4,3,2,1};
	Count_sort(arr);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
}
