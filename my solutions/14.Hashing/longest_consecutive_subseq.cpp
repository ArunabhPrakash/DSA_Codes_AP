#include<iostream>
#include<vector>
#include<unordered_map>
class Solution {//running in leetcode
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int,int> mappy;
        int maxc=INT_MIN;
        vector<bool> visited (nums.size(),false);
        for(int i=0;i<nums.size();i++){
            mappy[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                visited[i]=true;
                int pred=nums[i]-1;
                int succ=nums[i]+1;
                int count =1;
                while(mappy.find(pred)!=mappy.end()){
                    count++;
                    visited[mappy[pred]]=true;
                    pred--;
                    
                }
                while(mappy.find(succ)!=mappy.end()){
                    count++;
                    visited[mappy[succ]]=true;
                    succ++;
                    
                }
                maxc=max(count,maxc);
            }
        }
    return maxc;
    }
};
