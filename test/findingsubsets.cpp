#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
bool compare(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}
	return a.length()<b.length();
}
void subsets(vector<string> &str,string a,int i,string conc){
	if(a[i]=='\0'){
		str.push_back(conc);
		return;
	}
	else{
		subsets(str,a,i+1,conc);
		conc=conc+a[i];
		subsets(str,a,i+1,conc);
		return;
	}
}
int main(){
	string a="abc";
	vector<string> str;
	string conc;
	subsets(str,a,0,conc);
	sort(str.begin(),str.end(),compare);
	for(int i=0;i<str.size();i++){
		cout<<str[i]<<endl;
	}
}
