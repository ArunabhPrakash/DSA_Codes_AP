#include<iostream>
using namespace std;

int main(){
	string big="codingminutes";
	string small="cinesy";
	int j=0;
	for(int i=0;big[i]!='\0';i++){
		if(small[j]==big[i]){
			j++;
		}

	}
			
	if(j==small.length()){
			cout<<"yes";
			
		}	
	else{
		cout<<"no";
	}
	
}
