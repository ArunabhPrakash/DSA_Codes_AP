#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char a[]={'a','b','c','d','e','\0'};
	char b[]="abcdefghi";
	char c[100];
	cin>>c;
	cout<<a<<b<<c;
	cout<<strlen(a)<<endl;//visible char
	cout<<sizeof(a)<<endl;//+null char
	return 0;
}
