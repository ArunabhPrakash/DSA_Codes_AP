#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
	public:
		int data;
	Node* left;
	Node* right;
	
		Node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
Node* buildTree(){
	int d;
	cin>>d;
	if(d!=-1){
		Node* root= new Node(d);
		root->left=buildTree();
		root->right=buildTree();
		return root;
	}
	else{
		Node *root=NULL;
		return root;
	}
	
}

void preorder(Node* root){
	cout<<root->data;
	if(root->left!=NULL){
		preorder(root->left);
	}
	if(root->right!=NULL){
		preorder(root->right);
	}
}
void inorder(Node* root){
	if(root->left!=NULL){
		inorder(root->left);
	}
	cout<<root->data;
	if(root->right!=NULL){
		inorder(root->right);
	}
}
void postorder(Node* root){
	if(root->left!=NULL){
		postorder(root->left);
	}
	if(root->right!=NULL){
		postorder(root->right);
	}
	cout<<root->data;
}
void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* t = q.front();
		q.pop();
		if(t==NULL){
			if(!q.empty()){
				cout<<"\n";
				q.push(NULL);
			}
		}
		else{
		
		cout<<t->data;
		if(t->left!=NULL){
			q.push(t->left);
		}
		if(t->right!=NULL){
			q.push(t->right);
		}	
		}
	}
}

Node* levelOrderBuild(){
	int d;
	cin>>d;
	Node* root=new Node(d);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* t=q.front();
		q.pop();
		int l,r;
		cin>>l;
		if(l!=-1){
			t->left=new Node(l);
			q.push(t->left);
		}
		cin>>r;
		if(r!=-1){
			t->right=new Node(r);
			q.push(t->right);
		}
		
	}
	return root;
}
int height(Node* root){
	if(root->left==NULL and root->right==NULL){
		return 0;
	}
	else{
		int LH=INT_MIN;
		int RH=INT_MIN;
		if(root->left!=NULL)
		LH = height(root->left);
		if(root->right!=NULL)
		RH = height(root->right);
		return 1+max(LH,RH);
	}
}
int diameter(Node* root){
	if(root->left==NULL and root->right==NULL){
		return 0;
	}
	else{
		int LH=INT_MIN;
		int RH=INT_MIN;
		int LD=INT_MIN;
		int RD=INT_MIN;
		if(root->left!=NULL){
		LH = height(root->left);	
		LD=diameter(root->left);
		}
		
		if(root->right!=NULL){
		RH = height(root->right);	
		RD=diameter(root->right);
		}
		
		int heightF = 1+LH+RH;
		
		
		
		return max(LD,max(RD,heightF));
	}
	
}
void kLevel(Node* root,int k){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int lvl=0;
	while(!q.empty()){
		Node* t= q.front();
		q.pop();
		if(t==NULL){
			lvl++;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			if(lvl==k){
				cout<<t->data<<" ";
			}
			if(t->left!=NULL){
				q.push(t->left);
				
			}
			if(t->right!=NULL){
				q.push(t->right);
			}
		}
	}
}
int sumofNodes(Node* root){
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	else{
		int sum = root->data;
		if(root->left!=NULL){
			sum+=sumofNodes(root->left);
		}
		if(root->right!=NULL){
			sum+=sumofNodes(root->right);
		}
		return sum;
	}
}
int mindepth(Node* root){
	if(root->left==NULL and root->right==NULL){
		return 0;
	}
	else{
		int LH=INT_MAX;
		int RH=INT_MAX;
		if(root->left!=NULL)
		LH = mindepth(root->left);
		if(root->right!=NULL)
		RH = mindepth(root->right);
		return 1+min(LH,RH);
	}
}
bool isSymmetric(Node* root){
	stack<Node*> s;
	s.push(root);
	s.push(root);
	while(!s.empty()){
		Node* first = s.top();
		s.pop();
		Node* second=s.top();
		s.pop();

		if(first==NULL and second!=NULL){
			return false;
		}
		else if(first!=NULL and second==NULL){
			return false;
		}
		else if(first==NULL and second==NULL){
			continue;
		}
		else{
			if(first->data!=second->data){
				return false;
			}
			else{
				s.push(first->left);
				s.push(second->right);
				s.push(first->right);
				s.push(second->left);
			}
		}
		
	}
	return true;
}
int main(){
//	Node* root=buildTree();
//	preorder(root);
//	cout<<"\n";
//	inorder(root);
//	cout<<"\n";
//	postorder(root);
//	cout<<"\n";
//	levelOrder(root);
	Node* root2=levelOrderBuild();
	cout<<"\nPreorder\n";
	preorder(root2);
	cout<<"\nInorder\n";
	inorder(root2);
	cout<<"\nPostorder\n";
	postorder(root2);
	cout<<"\n";
	cout<<"height: "<<height(root2)<<" ";
	cout<<"\ndiameter: "<<diameter(root2);
	int k=2;
	cout<<"\n"<<k<<" lvl nodes: ";
	kLevel(root2,k);
	cout<<"\nSum of Nodes: "<<sumofNodes(root2);
	cout<<"\nMinDepth: "<<mindepth(root2);	
	cout<<"\nisSymmetric: "<<isSymmetric(root2);
}
