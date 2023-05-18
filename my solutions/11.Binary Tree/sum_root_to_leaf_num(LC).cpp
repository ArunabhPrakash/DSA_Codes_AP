#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>//for int max but working w/o that as well
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

	int sumNumbersHelper(Node* root,vector<int> &arr){
        arr.push_back(root->data);
        cout<<"\ndata "<<root->data;
        if(root->left==NULL and root->right==NULL){
            int size = arr.size();
            int temp = size-1;
            int sum=0;
            for(int i=0;i<size;i++){
                sum+=(arr[i]*pow(10,temp));
                temp--;
                cout<<"\nsum at each step: "<<sum;
            }
            cout<<"\nsum at leaf "<<sum;
            arr.pop_back();
            return sum;
        }
        else{
            int sum=0;
            if(root->left!=NULL){
                sum+=sumNumbersHelper(root->left,arr);
                
            }
            if(root->right!=NULL){
                sum+=sumNumbersHelper(root->right,arr);
                
            }
            arr.pop_back();
            return sum;
        }
        
    }
    int sumNumbers(Node* root) {
        vector<int> arr;
        return sumNumbersHelper(root,arr);
    }
    
int main(){
	Node* root =buildTree();
	printPreorder(root);
	cout<<endl<<sumNumbers(root);
}
