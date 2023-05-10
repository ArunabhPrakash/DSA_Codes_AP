#include<iostream>
#include<string.h>
using namespace std;
 
bool arePermutation(string A, string B)
{
	int match=0;
  for(int i=0;B[i]!='\0';i++){
  	for(int j=0;A[j]!='\0';j++){
  		if(B[i]==A[j]){
  			match=1;
		  }
	  }
	  if(match!=1){
	  	return false;
	  }
	  match=0;
  }
  return true;
}

int main(){

	string A="abcd";
	string B="bcda";
	cout<<arePermutation(A,B);
}
