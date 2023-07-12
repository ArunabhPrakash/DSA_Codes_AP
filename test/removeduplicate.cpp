#include<iostream>
#include<algorithm>
#include<string.h>
#include<unordered_set>
using namespace std;

string removeDuplicate(string s){//nlogn
    sort(s.begin(),s.end());
    string output;
    for(int i=0;s[i]!='\0';i++){
    	if(s[i]!=s[i+1]){
    		output+=s[i];
		}
	}
	return output;
}
string removeDuplicate2(string s){
    unordered_set<char> m;
    string str;
	for(int i=0;s[i]!='\0';i++){
    	if(m.find(s[i])==m.end()){
    		str+=s[i];
    		m.insert(s[i]);
		}
		
	}
	return str;
}

int main(){
	string s="geeksforgeeks";
	cout<<removeDuplicate2(s);
	
}
