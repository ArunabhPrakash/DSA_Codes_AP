#include<iostream>
using namespace std;

int main(){
	char route[1000];
	cin.getline(route,1000);
	int x=0;
	int y=0;
	for(int i=0;route[i]!='\0';i++){
		switch(route[i]){
			case 'N': y++;
			break;
			case 'S': y--;
			break;
			case 'W': x--;
			break;
			case 'E': x++;
			break;
		}
	}
	if(x>=0 and y>=0){
		while(x--){
			cout<<"E";
		}
		while(y--){
			cout<<"N";
		}
	}
	else if(x>=0 and y<0){
		while(x--){
			cout<<"E";
		}
		while(y++){
			cout<<"S";
		}
	}
	else if(x<0 and y>=0){
		while(x++){
			cout<<"W";
		}
		while(y--){
			cout<<"N";
		}
	}
	else{
		while(x++){
			cout<<"W";
		}
		while(y++){
			cout<<"S";
		}
	}
}
