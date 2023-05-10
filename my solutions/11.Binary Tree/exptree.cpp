#include<iostream>
#include<string>
#include<queue>
using namespace std;
 
struct Node {
    char key;
    Node* left, *right;
    
		Node(char d){
			key =d;
			left=right=NULL;
		}
};

int evalTree(Node* root){//this could have been done better by using post order execution
    cout<<root->key;
	if(root==NULL){
    	return -1;
	}
	else{
		if(root->left->key=='+' ||root->left->key=='-' ||root->left->key=='*' ||root->left->key=='/'){
			switch(root->key){
				case '+': return evalTree(root->left)+((int)root->right->key-48);
							break;
				case '-': return evalTree(root->left)-((int)root->right->key-48);
							break;
				case '*': return evalTree(root->left)*((int)root->right->key-48);
							break;
				case '/': return evalTree(root->left)/((int)root->right->key-48);
							break;
				default: return -1;
			}
		}
		else if(root->right->key=='+' ||root->right->key=='-' ||root->right->key=='*' ||root->right->key=='/'){
			switch(root->key){
				case '+': return ((int)root->left->key-48)+evalTree(root->right);
							break;
				case '-': return ((int)root->left->key-48)-evalTree(root->right);
							break;
				case '*': return ((int)root->left->key-48)*evalTree(root->right);
							break;
				case '/': return ((int)root->left->key-48)/evalTree(root->right);
							break;
				default: return -1;
			}
		}
		else{
			switch(root->key){
				case '+': return ((int)root->left->key-48)+((int)root->right->key-48);
							break;
				case '-': return ((int)root->left->key-48)-((int)root->right->key-48);
							break;
				case '*': return ((int)root->left->key-48)*((int)root->right->key-48);
							break;
				case '/': return ((int)root->left->key-48)/((int)root->right->key-48);
							break;
				default: return -1;
			}
		}
		
	}
}

Node* levelorderBuild(){
	char d;
	cin>>d;
	Node *root=new Node(d);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *t=q.front();
		q.pop();
		char left;
		cin>>left;
		if(left!='z'){
			Node *leftn=new Node(left);
			t->left=leftn;
			q.push(leftn);
		}
		char right;
		cin>>right;
		if(right!='z'){
			Node *rightn=new Node(right);
			t->right=rightn;
			q.push(rightn);
		}
		
	}
	return root;
}

int main(){
	Node *root=levelorderBuild();
	cout<<evalTree(root);
}
