#include<iostream>
#include"list.h"
using namespace std;

Node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	Node *c;
	if(a->getData() < b->getData){
		c=a;
		c->next = merge(a->next,b);
	}
	else{
		c=b;
		c->next = merge(a,b->next);
	}
	return c;
}
