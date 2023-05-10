#include<iostream>
using namespace std;
void replacemod20(string line){
	string op;
	string str="%20";
	for(int i=0;line[i]!='\0';i++){
		if(line[i]==' '){
			op.append(str);
		}
		else{
			op+=line[i];
		}
	}
	cout<<op;
}
int main(){
	string line = "hello world, how are you?";
	replacemod20(line);
}
