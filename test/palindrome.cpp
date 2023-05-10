#include<iostream>
#include<string.h>
using namespace std;

bool isPalindrome(string str)
{
    int len=str.size();
    for(int i=0;i<=len-i-1;i++){
    	if(str[i]!=str[len-i-1]){
    		return false;
		}
	}
	return true;
}

int main(){
	string sentence;

	getline(cin,sentence);
	cout<<isPalindrome(sentence);
}
