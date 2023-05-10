#include<iostream>
#include"list.h"
using namespace std;

int main(){
	int key;
	//cin>>key;
	List l;
	l.push_front(1);
	l.push_front(0);
	l.push_back(3);
	l.push_back(4);
	l.insert(2,2);
	l.insert(10,0);
//	cout<<"pos"<<l.search(key)<<endl;
//	cout<<"pos"<<l.recursiveSearch(key)<<endl;
	Node* head = l.begin();
	while(head!=NULL){
		cout<<head->getData()<<"->";
		head=head->next;
	}
	l.remove_pos(2);
	head=l.begin();
	while(head!=NULL){
		cout<<head->getData()<<"->";
		head=head->next;
	}
	cout<<endl;
	l.reversefun();// l has head pointer will be update automatically and can be accessed using .begin()
	head=l.begin();
		while(head!=NULL){
		cout<<head->getData()<<"->";
		head=head->next;
	}
	head=l.begin();
	cout<<head->getData();
	l.pop_front();
	
	
}

