#include<iostream>
#include<string.h>
using namespace std;

int main(){
		int n;
	cin>>n;
	cin.get();
	char sentence[1000];
	char largest[1000];

	int len=0;
	int largestlen=0;
	
		while(n--){
		cin.getline(sentence,1000);
		int len = strlen(sentence);
		if(len>largestlen){
			largestlen=len;
			strcpy(largest,sentence);
		}
	}
	cout<<largest;
}
