#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	map<string,vector<string> > phonebook;
	phonebook["prateek"].push_back("2321312");
	phonebook["prateek"].push_back("32423535");
	phonebook["suraj"].push_back("2321312");
	for(auto word:phonebook){
		cout<<phonebook[word]<<endl;
	}
	
}
