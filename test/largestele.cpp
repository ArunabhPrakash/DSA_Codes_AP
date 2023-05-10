#include<iostream>
#include<vector>
using namespace std;

int largestElement(vector<int> arr) {
    int ms=arr[0];
    for(int i=0;i<arr.size();i++){
	
        ms=max(ms,arr[i]);
    }
    return ms;
}

int main(){
	vector<int> arr;
	arr.reserve(5);
	for(int i=0;i<arr.capacity();i++){
		cin>>arr[i];
	}
	cout<<largestElement(arr);
}
