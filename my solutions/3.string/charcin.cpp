#include<iostream>
using namespace std;

int main(){
	char sentence[1000];
	char temp=cin.get();//if remove this then prog wont run, but if # in while then it will run without this
	int len=1;
	cout<<temp;
	while(temp!='\n'){// if use # then can also print line change
		len++;
		cout<<temp;
		temp=cin.get();
	}
	cout<<"length"<<len<<endl;
}
