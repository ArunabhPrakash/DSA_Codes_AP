#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
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

void printPreorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

bool isSymmetric(Node* root) {//cant create hashmap for pair
        queue<pair<Node*,int>> q;
        unordered_map<pair<int,int>,int> mappy;//for each val, store its pos, with its val, match both
        q.push(root,0);
        q.push(null,0);
        int lvlcount =0;
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* tempPt = temp.first;
            int vheight = temp.second;
            if(tempPt==NULL and !q.empty()){
                lvlcount++;
                q.push(NULL,0);
            }
            else if(tempPt==NULL and q.empty()){
                break;
            }
            else{
            mappy[(lvlcount,vheight)]=tempPt->data;
            if(tempPt->left!=NULL){
                q.push(tempPt->left,vheight-1);
            }
            if(tempPt->right!=NULL){
                q.push(tempPt->right,vheight+1);
            }
            }
           
        }
        for(auto i:mappy){
            auto x = i.first;
            int lvl = x.first;
            int revheight=-(x.second);
            if(mappy[(lvl,revheight)]!=mappy[(x.first,x.second)]){
                return false;
            }
        }
        return true;
    }
int main(){
	Node* root =buildTree();
	printPreorder(root);
	cout<<isSymmetric(root);
}
