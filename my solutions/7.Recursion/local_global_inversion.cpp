#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &array,int s,int e){
	int i=s;
	int m=(s+e)/2;
	int j=m+1;
	int cnt=0;
	vector<int> temp;
	while(i<=m and j<=e){
		if(array[i]<array[j]){
			temp.push_back(array[i]);//no need to maintain k and easy insertion using vector
			i++;
		}
		else{
			cnt+=(m-i+1);//for each element on j side, it has inversion with all elements from i to mid so we increase count by that much
			temp.push_back(array[j]);
			j++;
		}
	}
	while(i<=m){
		temp.push_back(array[i++]);
		
	}
	while(j<=e){
		temp.push_back(array[j++]);
	}
	int k=0;
	for(int idx = s;idx<=e;idx++){
		
		array[idx] = temp[k++];
	}
	return cnt;
}

int inversion_count(vector<int> &array,int s,int e){
	if(s>=e){
		return 0;
	}
	
	int mid=(s+e)/2;
	int C1=inversion_count(array,s,mid);
	int C2=inversion_count(array,mid+1,e);
	int CI=merge(array,s,e);
    return C1+C2+CI;

}
    bool isIdealPermutation(vector<int>& nums) {
		int LI = 0;
		   for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
            LI++;
        }
    }
    int final = inversion_count(nums,0,nums.size()-1);
    
 
    return LI==final;
}

int main(){
	vector<int> arr = {1,0,2};
	cout<<isIdealPermutation(arr);
}
