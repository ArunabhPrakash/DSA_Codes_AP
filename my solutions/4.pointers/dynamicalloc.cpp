#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i]=i;
		cout<<arr[i]<<" ";
		
	}
	delete [] arr;
	cout<<arr<<endl<<arr[2];
	return 0;
}
