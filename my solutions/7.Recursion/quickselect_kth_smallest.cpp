#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a,int s,int e){//worst case increasing or decreasing order
	int pivot=a[e];
	int i = s-1;
	for(int j=s;j<e;j++){
		if(a[j]<pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}
int quickselect(vector<int> &a,int s,int e,int k){//quick select kth smallest element index wise, like 4th element has index 3

	
			int p = partition(a,s,e);
			if(p==k){
			return a[p];
			}
			else if(p>k){
			return quickselect(a,s,p-1,k);
			}
			else{
			return quickselect(a,p+1,e,k);
			}
	
	

}

int main(){
	vector<int> arr{10,5,2,0,7,6,4};
	int k = 3;//3rd position, index 2nd, index(0,1,2)
	int s = k-1;//adjusting position to index
	int n=arr.size();
	cout<<quickselect(arr,0,n-1,s);

}

