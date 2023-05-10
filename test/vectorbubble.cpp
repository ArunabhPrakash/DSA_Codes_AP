#include<iostream>
#include<vector>
using namespace std;
vector<int> bubble_sort(vector<int> arr){
	int n=arr.size();

	bool swapped=false;	
	for(int times=1;times<=n-1;times++){
		for(int j=0;j<=n-times-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
				bool swapped=true;
			}
		}
		if(swapped==false){
			break;
		}
	}
	return arr;
}
int main(){
	vector<int> arr={5,4,3,2,1};
	arr=bubble_sort(arr);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	
}
