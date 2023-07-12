#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
 
int binaryToDecimal(string s)
{
	int sum=0;
	int n=s.length();
	int myint=stoi(s);
    for(int i=n-1;i>=0;i--){
    	int num=myint%10;
    	myint=myint/10;
		sum+=num*pow(2,n-1-i);
	}
	return sum;
}

int main(){
	string s=to_string(111);
	cout<<binaryToDecimal(s);
	
}
