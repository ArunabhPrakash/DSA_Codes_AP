#include<iostream>
#include<string.h>
using namespace std;

bool notpalindrome(string palindrome){
	int j=palindrome.length()-1;
	for(int i=0;i<j;i++){
		if(palindrome[i]!=palindrome[j]){
			return true;
		}
		j--;
	}
	return false;
}
string breakPalindrome(string palindrome) {
	int n=palindrome.length();
	if(n<=1){
		return {};
	}
        for(int i=0;palindrome[i]!='\0';i++){
        	if(palindrome[i]!='a'){
        		char temp=palindrome[i];
				palindrome[i]='a';
        		if(notpalindrome(palindrome)){
        			return palindrome;
				}
				else{
					palindrome[i]=temp;
				}
			}
		}
		
		for(int i=n-1;i>=0;i--){
			if(palindrome[i]!='b'){
				char temp=palindrome[i];
				palindrome[i]='b';
				if(notpalindrome(palindrome)){
					return palindrome;
				}
				else{
					palindrome=temp;
				}
			}
		}
		
}

int main(){
	string a="aba";
	cout<<breakPalindrome(a);
}
