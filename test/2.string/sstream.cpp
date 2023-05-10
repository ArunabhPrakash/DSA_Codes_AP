#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
	string input;
	getline(cin,input);
	stringstream ss(input);
	string token;
	vector<string> tokens;
	while(getline(ss,token,' ')){
		tokens.push_back(token);
	}
	for(int i=0;i<tokens.size();i++){
		cout<<tokens[i]<<" ";
	}
}
