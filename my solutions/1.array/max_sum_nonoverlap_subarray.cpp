#include<iostream>
#include<vector>
using namespace std;//not submitted in LC


    bool slidingwindow(vector<int> &nums,vector<int> &prefixvec,int len,int start,int end){
    if((end-start)+1<len){
        return false;
    }
    int k=1;
    prefixvec[start]=nums[start];
       for(int i=start+1;i<=end;i++){
        if(k<len){
            prefixvec[i]=prefixvec[i-1]+nums[i];
            k++;
        }
        else{
            prefixvec[i]=prefixvec[i-1]-nums[i-(k)];
            prefixvec[i]+=nums[i];
        }
    }
    return true;
}
    int maxFunc(vector<int>& nums, int firstLen, int secondLen) {
        
		vector<int> prefixvec(nums.size());
        slidingwindow(nums,prefixvec,firstLen,0,nums.size()-1);
        int maxFirst = INT_MIN;
        int maxSecond = INT_MIN;
        int firstMark,secondMark;
		for(int i=firstLen-1;i<nums.size();i++){
            if(maxFirst<prefixvec[i]){
                maxFirst=prefixvec[i];
                firstMark=i;
            }
        }
        cout<<"\n";
        for(int i=0;i<prefixvec.size();i++){
        	cout<<prefixvec[i]<<" ";
		}
        cout<<"\n"<<maxFirst<<"\n";
        int beginfM=(firstMark-firstLen)+1;
        cout<<"b:"<<beginfM<<" e:"<<firstMark<<"\n";
        if(slidingwindow(nums,prefixvec,secondLen,0,beginfM-1)){
            
			for(int i=0;i<prefixvec.size();i++){
        	cout<<prefixvec[i]<<" ";
			}
			for(int i=secondLen-1;i<beginfM;i++){
                if(maxSecond<prefixvec[i]){
                    maxSecond=prefixvec[i];
                    secondMark=i;
                }
            }
        }
        
        if(slidingwindow(nums,prefixvec,secondLen,firstMark+1,nums.size()-1)){
            for(int i=firstMark+secondLen;i<nums.size();i++){
                    if(maxSecond<prefixvec[i]){
                    maxSecond=prefixvec[i];
                    secondMark=i;
                }
            }
        }
        int beginSM=(secondMark-secondLen)+1;
             cout<<"b2:"<<beginSM<<" e2:"<<secondMark<<"\n";
		cout<<maxSecond<<"\n";
        return maxFirst+maxSecond;

    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
		int len1=max(firstLen,secondLen);
		int len2=min(firstLen,secondLen);
		return max(maxFunc(nums,len1,len2),maxFunc(nums,len2,len1));
	}
    
int main(){
	vector<int> nums = {0,6,5,2,2,5,1,9,4};
	cout<<maxSumTwoNoOverlap(nums,1,2);
}
