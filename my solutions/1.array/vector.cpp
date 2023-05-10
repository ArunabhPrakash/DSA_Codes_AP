#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> arr;
	arr.reserve(3); //set size
	arr.push_back(3);//push values
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(6);//capacity doubled since higher than reserve
	cout<<arr.size()<<endl<<arr.capacity()<<endl;
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<endl;
	}
	arr.pop_back();
		for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<endl;
	}
	vector<int> arr2(10,7);//fill constructor to initialise vectors with a value
	for(int i=0;i<arr2.size();i++){
	cout<<arr2[i]<<endl;
	}
	return 0;
}

