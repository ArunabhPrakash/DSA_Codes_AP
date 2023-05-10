#include<iostream>
using namespace std;

int main(){
	char numbers[][10]={
		"one",
		"two",
		"three",
		"forty",
		"eight",
		"hundred",
	};
	int i=3;
	cout<<numbers[i][2]<<endl;
	for(int i=0;i<6;i++){
		cout<<numbers[i];//happens only in char array
	}
	return 0;
	
}
