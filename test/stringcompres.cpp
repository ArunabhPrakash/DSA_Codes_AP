#include<iostream>
#include<string.h>
using namespace std;

string compress(string s){
	int n=s.length();
	int count=1;
	string output;
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){
			count++;
		}
		else{
			output+=s[i];
			if(count!=1){
				output+=to_string(count);
				count=1;
			}
		}
		
		
	}
	if(output.length()>s.length()){
		return s;
	}
	else{
		return output;
	}
}
int main(){
	string s1 = "aaabbbcccc";
	s1=compress(s1);
	cout<<s1;
	string s2="abc";
	s2=compress(s2);
	cout<<s2;
	
}
