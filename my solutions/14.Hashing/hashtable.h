#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Node{
	public:
		string key;
		T value;
		Node *next;
		
		Node(string key,T value){
			this->key=key;
			this->value=value;
			next=NULL;
		}
		~Node(){
			if(next!=NULL){
				delete next;
			}
		}
};
template<typename T>
class Hashtable{
	Node<T> **table;
	int cs;
	int ts; 
	
	int hashFn(string key){
		int idx = 0;
		int power = 1;
		for(auto ch:key){
			idx = (idx+ch*power)%ts;
			power = (power*29)%ts;//doing this so num doesnt become too big
		}
		return idx;
	}
	void rehash(){
		Node<T> **oldTable = table;
		table = new Node<T>*[2*ts+1];
		int oldTs = ts;
		cs=0;
		ts = 2*ts+1;
		table = new Node<T>*[ts];
		for(int i=0;i<ts;i++){
			table[i]=NULL;
		}//same as public initialization till now
		for(int i=0;i<oldTs;i++){
			Node<T> *temp = oldTable[i];
			while(temp!=NULL){
				string key= temp->key;
				T value = temp->value;
				insert(key,value);
				temp = temp->next;
			}
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}
		delete []oldTable;
	}

public:
	Hashtable(int default_size=7){
		cs = 0;
		ts = default_size;
		
		table = new Node<T>*[ts];
		
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
	}
	void insert(string Key,T val){
		int idx = hashFn(Key);
		Node<T>* n = new Node<T>(Key,val);
		n->next=table[idx];//insertion at head of LL
		table[idx]=n;
		cs++;
		float load_factor = cs/float(ts);
		if(load_factor > 0.7){
			rehash();
		}
		
	}
	T* search(string Key){//if obj present then return address else return NULL, cant use only T cause NULL cant be returned in all datatype
		int idx = hashFn(Key);
		Node<T> *temp = table[idx];
		while(temp!=NULL){
			if(temp->key == Key){
				return &temp->value;
			}
			temp=temp->next;
		}
		return NULL;
	}
	
	void erase(string Key){
		int idx = hashFn(Key);
		Node<T> *temp = table[idx];
		Node<T> *prev=temp;
		while(temp!=NULL){
			if(temp->key == Key){
				prev->next=temp->next;
				temp->next=NULL;
				delete temp;
				return;
			}
			else{
				prev=temp;
				temp=temp->next;

			}
						
		}
	}
	T& operator[] (string Key){
		T* valueFound = search(Key);
		if(valueFound==NULL){
			T object;
			insert(Key,object);
			valueFound = search(Key);
		}
		return *valueFound;
	}
	void print(){
		for(int i=0;i<ts;i++){
			cout<<"Bucket "<<i<<"->";
			Node<T> *temp=table[i];
			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp = temp->next;
			}
			cout<<endl; 
		}
	}
};
