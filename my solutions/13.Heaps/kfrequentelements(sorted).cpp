class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> pi;
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        vector<int> result;
        int count=1;
        int j=1;
        if(nums.size()==0 or nums.size()==1){
            return nums;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                if(j<=k){
                    heap.push({count,nums[i-1]});
                    count=1;
                    j++;
                }
                else{
                    pair<int,int> temp = heap.top();
                    if(temp.first<count){
                    heap.pop();
                    heap.push({count,nums[i-1]});
                        
                    }
                    count=1;
                }
            }
        }
        if(j<=k){
                    heap.push({count,nums[nums.size()-1]});
                    count=1;
                }
                else{
                    pair<int,int> temp = heap.top();
                    if(temp.first<count){
                    heap.pop();
                    heap.push({count,nums[nums.size()-1]});
                        
                    }
                    count=1;
                }
        
        while(!heap.empty()){
            pair<int,int> temp = heap.top();
            result.push_back(temp.second);
            heap.pop();
        }
        return result;
    }
};
