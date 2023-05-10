#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2, vector<int> (nums1.size()));
		int k=0;
		for(int i=0;i<nums1.size();i++){
			int count=0;
			if(nums1[i]!=nums1[i-1] or i==0){
					for(int j=0;j<nums2.size();j++){
					if(nums1[i]!=nums2[j]){
						count++;
					}
				
				}
			}
		
			if(count==nums2.size()){
				ans[0][k]=nums1[i];
				k++;
			}
		}
		k=0;
		for(int i=0;i<nums2.size();i++){
        	int count=0;
        	
			if(nums2[i]!=nums2[i-1] or i==0){
				for(int j=0;j<nums1.size();j++){
	        		if(nums2[i]!=nums1[j]){
						count++;
					}
					
				}		
			}
			
			if(count==nums1.size()){
				ans[1][k]=nums2[i];
				k++;
			}
		}
	 
		return ans;
    }
};

int main(){
	 vector<int> nums1 = {1,2,3,3}; 
	 vector<int> nums2 = {1,1,2,2};
	 Solution s;
	 vector<vector<int>> a;
	 a=s.findDifference(nums1,nums2);
	 for(int i=0;i<a.size();i++){
	 	for(int j=0;j<a[i].size();j++){
	 		cout<<a[i][j]<<" ";
		 }
		 cout<<endl;
	 }
}
