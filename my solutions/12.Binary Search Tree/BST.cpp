#include<iostream>
#include<vector>
using namespace std;

class Node{
	public:
		int key;
		Node *left;
		Node *right;
		
		Node(int key){
			this->key = key;
			left = right = NULL;
			
		}
		
};

Node* insert(Node*root,int key){
	if(root==NULL){
		return new Node(key);
	}
	if(key< root->key){
		root->left = insert(root->left,key);
		
	}
	else{
		root->right = insert(root->right,key);
		 
	}
	return root;
}

bool search(Node *root,int key){
	if(root==NULL){
		return false;
	}
	if(root->key==key){
		return true;
	}
	if(key< root->key){
		return search(root->left,key);
	}
	return search(root->right,key);
}
void printInorder(Node *root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->key<<" ,";
	printInorder(root->right);
}

Node* findMin(Node* root){
	while(root->left!=NULL){
		root = root->left;
		
	}
	return root;
}
Node* remove(Node* root,int key){
	if(root==NULL){
		return NULL;
	}
	if(key<root->key){
		root->left=remove(root->left,key);
	}
	else if(key>root->key){
		root->right = remove(root->right,key);
	}
	else{
		//no child
		if(root->left==NULL and root->right==NULL){
			delete root;
			root = NULL;
			return root;
		}
		//single child
		else if(root->left == NULL){
			Node* temp=root;
			root= root->right;
			delete temp;
			
		}
		else if(root->right == NULL){
			Node* temp=root;
			root=root->left;
			delete temp;
		}
		//2children
		else{
			Node *temp = findMin(root->right);
			root->key = temp->key;
			root->right = remove(root->right,temp->key);
			
		}
	}
	return root;
}

void printRange(Node* root,int k1,int k2){
	if(root==NULL){
		return;
	}
	if(root->key>=k1 and root->key<=k2){
		printRange(root->left,k1,k2);
		cout<<root->key<<" ,";
		printRange(root->right,k1,k2);
	}
	else if(root->key>k2){
		printRange(root->left,k1,k2);
	}
	else{
		printRange(root->right,k1,k2);
	}
}

void printRoot2leaf(Node* root,vector<int> &path){
	if(root==NULL){
		return;
	}
	if(root->left==NULL and root->right==NULL){
		for(int node:path){
			cout<<node<<"->";
		}
		cout<<root->key<<endl;//to print leaf node
		return;
	}
	path.push_back(root->key);
	printRoot2leaf(root->left,path);
	printRoot2leaf(root->right,path);
	path.pop_back();
	return;
}

int main(){
	int n; 
	Node *root = NULL;
	int a[] = {8,3,10,1,6,14,4,7,13};
	for(int x: a){
		root = insert(root,x);
	}
	/*printInorder(root);
	cin>>n;
	root = remove(root,n);
	printInorder(root);
	cout<<endl;
	printRange(root,5,12);*/
	vector<int> path;
	printRoot2leaf(root,path);
	
	
}
