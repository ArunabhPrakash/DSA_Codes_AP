#include<iostream>
using namespace std;
int printNodesAtDistK(node *root,node* target,int k){
	//base case
	if(root==NULL){
		return -1;
		
	}
	//reach target node
	if(root==target){
		printAtLevelK(target,k);
		return 0;
	}
	//other case
	int DL = printNodesAtDistanceK(root->left,target,k);
	if(DL!=-1){
		//2 cases
		//print the current node
		if(DL+1==k){
			cout<<root->data;
		}
		else{
			printAtLevelK(root->right,k-2-DL);
			
		}
		return 1+DL;
	}
	int DR = printNodesAtDistanceK(root->right,target,k);
	if(DR!=-1){
		//2 cases
		//print current node
		if(DR+1==k){
			cout<<root->data<<" ";
		}
		else{
			printLevelK(root->left,k-2-DR);
		}
		return 1+DR;
	}
	return -1;
}
int main(){
	
}
