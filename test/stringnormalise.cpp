#include<iostream>
#include<string.h>
using namespace std;



string normalize(const string &sentence) {
    string copy = sentence;
	copy[0]=toupper(copy[0]);
    
    for(int i=1;copy[i]!='\0';i++){
		
		if(copy[i-1]==' '){
			copy[i]=toupper(copy[i]);
			
		}
		else{
			copy[i]=tolower(copy[i]);
			
		}
		
		
	}
	
return copy;
}

int main(){
	string sentence="THIS is SO MUCH FUN";
	 cout<<normalize(sentence);
}
