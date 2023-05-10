#include<iostream>
#include<vector>
using namespace std;

vector<int> bubble_sort(vector<int> arr){
	int n=arr.size();
	for(int times=1;times<=n-1;times++){
		for(int j=0;j<=n-times-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	return arr;
}

vector<int> sortingWithComparator(vector<int> a, bool flag){
   int n=a.size();
   if(flag==1){
   	a=bubble_sort(a);
   }
   else{
   	a=bubble_sort(a);
   	for(int i=0,j=n-1;i<j;i++,j--){
   		swap(a[i],a[j]);
	   }
   }
    return a;
}

int main(){
	vector<int> arr={-2,3,4,-1,5,-12,6,1,3};
	int flag;
	cin>>flag;
	int n=arr.size();
	arr=sortingWithComparator(arr,flag);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
