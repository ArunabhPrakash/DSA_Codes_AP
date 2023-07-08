class Solution {//leetcode question
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        typedef pair<int, int> pi;
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        vector<int> result;
        int j=1;
        if(nums.size()==0 or nums.size()==1){
            return nums;
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=1;
            }
            else{
                m[nums[i]]++;
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(j<=k){
                heap.push({i->second,i->first});
                j++;
            }
            else{
                pair<int,int> temp = heap.top();
                if(i->second > temp.first){
                heap.pop();
                heap.push({i->second,i->first});    
                }
            }
        }
        
        while(!heap.empty()){
            pair<int,int> temp = heap.top();
            result.push_back(temp.second);
            heap.pop();
        }
        return result;
    }
};
