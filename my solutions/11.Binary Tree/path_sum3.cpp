#include<iostream>
#include<vector>
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int d){
			data =d;
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

    int findPath(Node* root,int targetSum,int &currsum){//O(n^2) TLE in LC
        if(root->left==NULL and root->right==NULL){
            currsum+=root->data;
            cout<<"root val:"<<root->data<<" currsum:"<<currsum;
            
            int count=0;
            if(currsum==targetSum){
                count++;
            }
            currsum-=root->data;
            return count;

        }
        else{
            currsum+=root->data;
            cout<<"root val:"<<root->data<<" currsum:"<<currsum;
            int count =0;
            if(currsum==targetSum){
                count++;
            }
            if(root->left!=NULL){
                cout<<"\ncalling f1 left: "<<root->left->data;
				count=count+findPath(root->left,targetSum,currsum);
                
            }
            if(root->right!=NULL){
            	cout<<"\ncalling f1 right: "<<root->right->data;
                count=count+findPath(root->right,targetSum,currsum);
            }
            currsum-=root->data;
            return count;
            
        }
    }
    int findPathmain(Node* root,int targetSum,int &currsum){
        
        int count = findPath(root,targetSum,currsum);
        currsum=0;
        if(root->left!=NULL){
        	cout<<"\ncalling f2 left: "<<root->left->data;
            count+=findPathmain(root->left,targetSum,currsum);
        }
        currsum=0;
        if(root->right!=NULL){
        	cout<<"\ncalling f2 right: "<<root->right->data;
            count+=findPathmain(root->right,targetSum,currsum);
        }
        currsum=0;
        return count;

    }
    int pathSum(Node* root, int targetSum) {
        int currsum=0;
        if(root==NULL){
            return 0;
        }
        return findPathmain(root,targetSum,currsum);
    }
    int main(){
    	Node* root = buildTree();
    	cout<<pathSum(root,3);
    
	}
