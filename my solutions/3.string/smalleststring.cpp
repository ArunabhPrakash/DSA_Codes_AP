#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string &a, string &b){
	return a+b<b+a;
}
int main(){
	vector<string> a = {"a","ab","aba"};
	string b;
	sort(a.begin(),a.end(),compare);
	for(int i=0;i<a.size();i++){
		b+=a[i];
	}
	cout<<b;
}
