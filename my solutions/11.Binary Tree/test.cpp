#include<unordered_set>
#include<iostream>
using namespace std;

int main(){
	unordered_set<int> m;
	m.insert(10);
	if(m.find(10)==m.end()){
		cout<<"no";
	}
	if(m.find(10)!=m.end()){
		cout<<"yes";
	}
	m.erase(10);
	if(m.find(10)==m.end()){
		cout<<"no";
	}
	if(m.find(10)!=m.end()){
		cout<<"yes";
	}
}
