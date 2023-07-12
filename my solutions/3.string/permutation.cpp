#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
 
bool arePermutation(string A, string B)
{
	unordered_map<char,int> m;
	for(int i=0;A[i]!='\0';i++){
		if(m.find(A[i])==m.end()){
			m[A[i]]=1;
			cout<<"\n"<<A[i]<<" "<<m[A[i]];
		}
		else{
			m[A[i]]++;
			cout<<"\n"<<A[i]<<" "<<m[A[i]];	
		}
	}
	for(int i=0;B[i]!='\0';i++){
		if(m.find(B[i])!=m.end()){
			m[B[i]]--;
			cout<<"\n"<<B[i]<<" "<<m[B[i]];
			if(m[B[i]]<0){
			return false;
			}	
		}
		else{
			cout<<B[i]<<"\nnotpresent\n";
			return false;
		}
		
	}
	for(auto i:m){
		cout<<"\n"<<i.first<<" "<<i.second;
		if(i.second!=0){
			return false;
		}
	}
	return true;
}

int main(){
	string a="abcabcabcabc";
	string b="aaaabbbbcccc";
	cout<<arePermutation(a,b);
}
