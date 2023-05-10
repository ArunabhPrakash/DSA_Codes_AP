#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main(){
	string s="hello world"; //dynamic array, size can be changed during runtime as well
	cout<<s<<endl;
	string s2("hello world");//using constructor
	cout<<s2<<endl;
	string s3;
	getline(cin,s3,'.');//take input in s and terminates at .
	cout<<s3<<endl;
	for( int ch=0;s3[ch]!='\0';ch++){
		cout<<s3[ch]<<",";
	}
	vector<string> sarr;//thru vector
	string temp;
	int n=3;
	while(n--){
		getline(cin,temp);
		sarr.push_back(temp);
		
	}
	for(int i=0;i<sarr.size();i++){
		cout<<sarr[i]<<endl;
	}
	
}
