#include<iostream>
using namespace std;

int main(){
	int marks[100]={-1};
	int n;
	cout<<"enter the no. of students";
	cin>>n;
	marks[0]=-1;
	for(int i=0;i<n;i++){
		cin>>marks[i];
		
	}
	
	for(int i=0;i<100;i++){
		cout<<marks[i]*2;
	}
}
