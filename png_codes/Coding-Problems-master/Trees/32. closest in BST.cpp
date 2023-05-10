#include<iostream>
using namespace std;

int findClosestInBST(Node *root,int target){
	int closest;
	int diff=INT_MAX;
	
	Node *temp = root;
	while(temp!=NULL){
		if current_diff = abs(temp->key - target);
		
		if(current_diff==0){
			return temp->key;
		}
		if(current_diff < diff){
			diff = current_diff;
			closest = temp->key;
		}
		if(temp->key < target){
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}
	}
	return closest;
}
