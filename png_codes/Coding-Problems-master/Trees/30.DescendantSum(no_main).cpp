#include<iostream>
using namespace std;
int replaceWithSum(node *root){
	//base case
	if(root==NULL){
		return 0;
	}
	//check leaf
	if(root->left==NULL and root->right==NULL){
		return root->data;
	}
	//recursive case
	int LS=replaceWithSum(root->left);
	int RS=replaceWithSum(root->right);
	
	int temp = root->data;
	root->data=LS+RS;
	return root->data +temp;
}
int main(){
	
}
