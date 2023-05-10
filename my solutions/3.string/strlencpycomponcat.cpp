#include<iostream>
#include<string.h>
using namespace std;

int main(){
	char a[1000] = "apple";
	char b[1000];
	cout<<strlen(a)<<endl;
	strcpy(b,a);
	cout<<b;
	cout<<strcmp(a,b);
	char web[]="www";
	char domain[]="codingminutes.com";
	strcpy(b,strcat(web,domain));
	cout<<b<<endl;
	cout<<strcmp(b,a);
	return 0;
}
