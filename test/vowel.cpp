#include<iostream>
#include<string.h>
using namespace std;

string vowel(string s){
    string vow="aeiou";
    string output;
	for(int i=0;s[i]!='\0';i++){
    	for(int j=0;vow[j]!='\0';j++){
    		if(s[i]==vow[j]){
    			output+=s[i];
			}
		}
	}
	return output;
	
    
} 
int main(){
	string s="abcde";
	s=vowel(s);
	cout<<s;
}
