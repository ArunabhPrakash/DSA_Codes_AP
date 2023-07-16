    int storeAll(TreeNode* root,unordered_set<int> &map,int &sum,int targetSum){
        
        sum+=root->val;//use map instead of set if multiple times a sum can be repeated in a root to leaf path
        
        int count=0;
        if(sum==targetSum){
            count++;
        }

            int remainVal = sum-targetSum;
           
            if(map.find(remainVal)!=map.end()){
                count++;
            }

        map.insert(sum);
        if(root->left!=NULL){
            count+=storeAll(root->left,map,sum,targetSum);
        }
        if(root->right!=NULL){
            count+=storeAll(root->right,map,sum,targetSum);
        }
  
            map.erase(sum);
  
        
        sum-=root->val;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        unordered_set<int> map;
        int sum=0;
        return storeAll(root,map,sum,targetSum);

    }
