#include<iostream>
#include<vector>
using namespace std;

long long int maxSubarrayProduct(vector<int> &arr)
{
	int n = arr.size();
long long ans=INT_MIN;
long long product=1;
	
for(int i=0;i<n;i++){
	product*=arr[i];
	ans=max(ans,product);
	if(arr[i]==0){product=1;}//resets and count after the split, we have max val before 0 already stored
}
	
product=1;
	
for(int i=n-1;i>=0;i--){
	product*=arr[i];
	ans=max(ans,product);
	if(arr[i]==0){product=1;}//resets and count after the split, we have max val before 0 already stored
}
return ans;//by doing both fwd and bwd traversal we get max skipping either first or last -ve no. when odd no. of -ve integers
}

int main()
{
	vector<int> arr = { -2,0,1,2,3};
	
	cout << "Maximum Sub array product is "
		<< maxSubarrayProduct(arr);
	return 0;
}

