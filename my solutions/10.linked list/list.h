#include<iostream>
using namespace std;
class List;//forward declr so we can use it Node class as a friend
class Node{
	int data;


public:
	Node* next;// data type node pointer like int pointer
	Node(int d):data(d),next(NULL){}//initialization list
	int getData(){
		return data;
	}
	~Node(){
		if(next!=NULL){
			delete next;//recursive call to delete 
		}
		cout<<"deleting node with data "<< data<<endl;
	}
	friend class List;//allows other class to accss it, can access public pvt protected
};

class List{
	Node * head;
	Node * tail;
	int searchHelper(Node *start,int key){ //if you want pointer as param, declare pointer here and while passing in function either pass pointer or address of a loc(&x)
		if(start==NULL){
			return -1;
		}
		if(start->data==key){
			return 0;
		}
		int subIdx = searchHelper(start->next,key);
		if(subIdx==-1){
			return -1;
		}
		return subIdx+1;
	}
public:
	List():head(NULL),tail(NULL){}
	
	Node* begin(){
		return head;
	}
	
	void push_front(int data){
		if(head==NULL){
			Node * n = new Node(data);
			head=tail=n;
			return;
		}
		else{
			Node * n = new Node(data);
			n->next = head;
			head= n;
		}
	}
	
	void push_back(int data){
		if(head==NULL){
			Node * n = new Node(data);
			head=tail=n;
			return;
		}
		else{
			Node * n = new Node(data);
			tail->next = n;
			tail=n;
		}
	}
	void insert(int data, int pos){ //here position is being counted from 0 like array (3rd element means 2nd pos)
		if(pos==0){
			push_front(data);
			return;
		}
		Node* temp = head;
		for(int jump=1;jump<=pos-1;jump++){
			temp=temp->next; 
		}
		Node *n = new Node(data);
		n->next=temp->next;
		temp->next=n;
		
	}
	int search(int key){
 
		Node * temp = head;
		int idx = 0;
 
		while(temp!=NULL){
			if(temp->data == key){
				return idx;
			}
			idx++;
			temp = temp->next;
		}	
		return -1;
	}
	int recursiveSearch(int key){
		int idx = searchHelper(head,key);
		return idx;
		
	}
	void pop_front(){
		Node *temp = head;
		head= head->next;
		temp->next=NULL;//to severe the link so whole LL is not destroyed
		delete temp;
	}
	void pop_back(){
		Node *temp = head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next=NULL;
		Node *n = tail;
		tail=temp;
		delete n;
		
		
	}
	void remove_pos(int pos){//here position is being counted from 0 like array (3rd element means 2nd pos)
		Node *temp = head;
		for(int i=1;i<=pos-1;i++){
			temp=temp->next;
		}
		Node *n=temp->next;
		temp->next=n->next;
		n->next=NULL;
		delete n;
		
	}
	Node* reverse(Node *head){//address of head is passed so at end we dont need to update head at end-logic right and now working
		Node *c=head;//if you dont return head, original head will point at last element after reverse and wont iterate correctly
		Node *p=NULL;
		Node *n;
		while(c!=NULL){
			n=c->next;
			c->next=p;
			p=c;
			c=n;
		}
		head=p;
		return head;
	}
	void reversefun(){
		head=reverse(head);
	}
	~List(){
		if(head!=NULL){
			delete head;
		}
			
			
	}
};
