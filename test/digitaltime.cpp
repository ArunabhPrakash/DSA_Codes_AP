#include<string>
#include<iostream>
using namespace std;

string convert_to_digital_time(int minutes){
	string hr=to_string(minutes/60);
	hr+=":";
	int temp=minutes%60;
	string min=to_string(temp);	
	if(temp<10){
	hr+="0";
	}
	hr+=min;
	return hr;
}
int main(){
	int minutes=127;
	cout<<convert_to_digital_time(minutes);
}
