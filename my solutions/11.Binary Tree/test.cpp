#include<iostream>
#include<vector>
using namespace std;
class Node{
	public:
		int val;
		Node *left;
		Node *right;
		
		Node(int d){
			val =d;
			left=right=NULL;
		}
};

Node* buildTree(){//returns Node pointer like some func returns int, as unlike stack it doesnt have cmnd to get head directly
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	Node* n = new Node(d);
	n->left = buildTree();//tree will build in preorder
	n->right = buildTree();
	return n;
}

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
    Node* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        findTP(root,p->val,v1);
        findTP(root,q,v2);
        int i=0;
        int j=0;
        Node* lca=NULL;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]->val == v2[i]->val){
                lca=v1[i];
                cout<<"\nval"<<v1[i]->val;
            }
            i++;
            j++;
            
        }
        return lca;
    }
    int main(){
    	Node* root = buildTree();
    	Node* temp = lowestCommonAncestor(root,5,4);
    	cout<<temp<<" "<<temp->val;
	}
