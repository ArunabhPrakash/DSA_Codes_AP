class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> stk;
        vector<int> result;
        stk.push(nums2[0]);
        for(int i=1;i<nums2.size();i++){
            while(!stk.empty() and stk.top()<nums2[i]){
                int t = stk.top();
                m[t]=nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(!stk.empty()){
            int t = stk.top();
            m[t]=-1;
            stk.pop();
        }
        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i])!=m.end()){
                result.push_back(m[nums1[i]]);
            }
        }
        return result;
    }
};
