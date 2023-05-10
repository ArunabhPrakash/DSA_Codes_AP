#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Node{
public:	
	char data;
	unordered_map<char,Node*> m;//at each node there is a map
	bool isTerminal;
	friend class Trie;
		Node(char d){
			data = d;
			isTerminal = false;
		}
		
};

class Trie{
	
	public:
		Node *root;
		Trie(){
			root = new Node('\0');
		}
		void insert(string word){
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
};
void searchHelper(Trie t,string document,int i,unordered_map<string,bool> &m){
		Node *temp = t.root;
		for(int j=i;j<document.length();j++){
			char ch=document[j];
			if(temp->m.count(ch)==0){
				return;
			}
			temp = temp->m[ch];
			if(temp->isTerminal){
				string out = document.substr(i,j-i+1);
				m[out]= true;
			}
		}
		return;
}
void documentSearch(string document, vector<string> words){
		//1. create trie of words
		Trie t;
		for(auto w:words){
			t.insert(w);
		}
		//2. searching (helper function)
		unordered_map<string,bool> m;
		for(int i=0;i<document.length();i++){
			searchHelper(t,document,i,m);//if present in trie insert in hashmap
		}
		//3 check words in hashmap
		for(auto w:words){
			if(m[w]){
				cout<<w<<"True"<<endl;
			}
			else{
				cout<<w<<"false"<<endl;
			}
		
		}
		return;
	}

int main(){
	string document = "little cute cate loves to code in c++, java and python";
	vector<string> words = {"cute cat","ttle","cat","quick","big"};
	documentSearch(document,words);
	return 0; 
	
}
