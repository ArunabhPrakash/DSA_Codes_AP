/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool findTP(TreeNode* root,int trgt,vector<TreeNode*> &v){
        if(root->val==trgt){
            v.push_back(root);
            return true;
        }
        else{
            v.push_back(root);
            if(root->left!=NULL){
                if(findTP(root->left,trgt,v)){
                    return true;
                }
            }
            if(root->right!=NULL){
                if(findTP(root->right,trgt,v)){
                    return true;
                }
            }
            v.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        findTP(root,p->val,v1);
        findTP(root,q->val,v2);
        int i=0;
        int j=0;
        TreeNode* lca=NULL;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]->val == v2[i]->val){
                lca=v1[i];
            }
            i++;
            j++;
            
        }
        return lca;
    }
};
