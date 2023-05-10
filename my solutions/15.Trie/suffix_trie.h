#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
	char data;
	unordered_map<char,Node*> m;//at each node there is a map
	bool isTerminal;
	friend class Trie;
	public:
		Node(char d){
			data = d;
			isTerminal = false;
		}
		
};

class Trie{
	Node *root;
	public:
		Trie(){
			root = new Node('\0');
		}
		void insert_helper(string word){
			Node *temp = root;//temp node to iterate on trie
			
			for(char ch: word){
				if(temp->m.count(ch)==0){//count checks what is inside map, if word not present then insert node else increase count, temp is only pointer to original hashmap
					Node *n = new Node(ch);
					temp->m[ch] = n;//stored location
				}
				temp=temp->m[ch];
			}
			temp->isTerminal = true;
		}
		
		bool search(string  word){
			Node *temp = root;
			for(char ch:word){
				if(temp->m.count(ch)==0){
					return false;
				}
				temp=temp->m[ch];
			}
			return temp->isTerminal;
		}
		void insert(string word){
			//pick all substrings from (i,eos) and insert helper
			for(int i=0;word[i]!='\0';i++){
				insert_helper(word.substr(i));
			}
		}
};
