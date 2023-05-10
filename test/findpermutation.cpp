#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void findpermutation(vector<string> &str,string a,int i,string conc){
	if(a[i]=='\0'){
		str.push_back(conc);
		return;
	}
	else{
		conc+=a[i];
		findpermutation(str,a,i+1,conc);
		for(int j=i+1;a[j]!='\0';j++){
			swap(a[i],a[j]);
			conc[i]=a[i];
			findpermutation(str,a,i+1,conc);
			swap(a[i],a[j]);
		}
		return;
	}
}
int main(){
	string a="abcd";
	vector<string> str;
	string conc;
	findpermutation(str,a,0,conc);
	for(int i=0;i<str.size();i++){
		cout<<str[i]<<endl;
	}	
}
