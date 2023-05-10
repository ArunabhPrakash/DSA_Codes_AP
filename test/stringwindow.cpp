#include<iostream>
#include<unordered_map>
using namespace std;

string stringwindow(string big,string small){
	int i=INT_MAX;
	int k=0;
	int window=INT_MIN;
	unordered_map<char,int> m;
	for(int j=0;big[j]!='\0';j++){
		if(k==small.length()){
			window=window-i+1;
			return big.substr(i,window);
		}
		else{
			char ch1=small[k];
			char ch2=big[j];
		
		
			if(m.count(ch1)){
			i=min(m[ch1],i);
			m.erase(ch1);
			k++;
			}
			else if(ch2==ch1){
			k++;
				if(j<i){
					i=j;
				}	
				else{
				window=j;	
				}
			
			}
			else{
			m[ch2]=j;
			}
		}
			
	}
	return "";
	
}
int main(){
	string s1="hello_world";
	string s2="olol";
	cout<<stringwindow(s1,s2);
	
}
