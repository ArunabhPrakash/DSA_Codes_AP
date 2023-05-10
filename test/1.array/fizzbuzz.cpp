#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


vector<string> fizzbuzz(int n){
    vector<string> str;
	for(int i=1;i<=n;i++){
    	if(i%3==0){
    		str.push_back("Fizz");
    		
		}
		else if(i%5==0){
			str.push_back("Buzz");
		}
		else if(i%3==0 and i%5==0){
			str.push_back("FizzBuzz");
		}
		else{
			str.push_back(to_string(i));
		}
	}
	return str;
	
}

int main(){
	int size;
	cin>>size;
	vector<string> str;
	str=fizzbuzz(size);
	

	
}
