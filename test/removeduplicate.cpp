#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

string removeDuplicate(string s){
    sort(s.begin(),s.end());
    string output;
    for(int i=0;s[i]!='\0';i++){
    	if(s[i]!=s[i+1]){
    		output+=s[i];
		}
	}
	return output;
}

int main(){
	string s="cccbbaa";
	string op;
	op=removeDuplicate(s);
	cout<<op;
	
}
