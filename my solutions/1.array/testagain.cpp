#include<iostream>
#include<vector>
using namespace std;

    int maxProduct(vector<int>& nums) {
        int first=-1;
        int last=-1;
        int countneg=0;
        int firstprod = 1;
        int lastprod = 1;
        int prod=1;
        int finalans=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
            	if(countneg%2==0){
            		
            		finalans = max(finalans,max(prod,0));
            		first =last=-1;
            		prod=1;
            		countneg=0;
				}
				else{
					int firstprodRight = prod/(firstprod*nums[first]);
          			int lastprodLeft = prod/(lastprod*nums[last]);
          			int finalansNotIncF=max(firstprod*nums[first],firstprodRight*nums[first]);
          			if(first==0){
          				firstprod=finalansNotIncF;
					}
           			int finalansF=max(finalansNotIncF,max(firstprod,firstprodRight));
                 	int finalansNotIncL=max(lastprod*nums[last],lastprodLeft*nums[last]);
					if(last==nums.size()-1){
						lastprod=finalansNotIncL;
					}
					int finalansL=max(finalansNotIncL,max(lastprod,lastprodLeft));
            		finalans=max(finalans,max(finalansF,finalansL));
            		first =last=-1;
            		prod=1;
					countneg=0;
				}
			}
			else{
				if(nums[i]<0){
				
                if(first==-1 and last==-1){
                    first=i;
                    firstprod = prod;
                }
                lastprod=1;
                last=i;
                countneg++;
                prod *=nums[i];
            	}
            	else{
                prod==0?prod=nums[i]:prod *=nums[i];
                lastprod *=nums[i];
            	}
            
			}
            
        }
        if(countneg%2==0){
            finalans=max(prod,finalans);
            
        }
        else{
					int firstprodRight = prod/(firstprod*nums[first]);
          			int lastprodLeft = prod/(lastprod*nums[last]);
          			int finalansNotIncF=max(firstprod*nums[first],firstprodRight*nums[first]);
          			if(first==0){
          				firstprod=finalansNotIncF;
					}
           			int finalansF=max(finalansNotIncF,max(firstprod,firstprodRight));
                 	int finalansNotIncL=max(lastprod*nums[last],lastprodLeft*nums[last]);
					if(last==nums.size()-1){
						lastprod=finalansNotIncL;
					}
					int finalansL=max(finalansNotIncL,max(lastprod,lastprodLeft));
            		finalans=max(finalans,max(finalansF,finalansL));
        }
    return finalans;
    }
 /*   int maxProduct(vector<int> nums){
    	vector<int> result(nums.size());
    	for(int i=0;i<nums.size();i++){
    		if(nums[i]<0){
    			result[i]=0;
			}
			else if(nums[i]>0){
				prod*=nums[i];
				result[i]=prod;
			}
		}
    	
	}*/

int main(){
	vector<int> nums = {-2,0,-1};
	cout<<maxProduct(nums);
}

