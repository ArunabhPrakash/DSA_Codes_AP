#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


void fizzbuzz(int n){
    vector<string> str;
	for(int i=1;i<=n;i++){
    	if(i%3==0){
    		cout<<"Fizz";
    		
		}
		if(i%5==0){
			cout<<"Buzz";
		}
		/*else if(i%3==0 && i%5==0){
			cout<<"FizzBuzz";
		}*/
		else{
			cout<<to_string(i);
		}
	}
	
	
}

int main(){
	int size;
	cin>>size;
	fizzbuzz(size);
	//for(int i=1;i<=size;i++){
	//	str[i];
	//}
	
}
