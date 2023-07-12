#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

vector<int> stringSearch(string big,string small){
		int count=0;
		vector<int> arr;
		for(int i=0;big[i]!='\0';i++){
		if(big[i]==small[0]){
			for(int j=0;small[j]!='\0';j++){
				if(big[i]==small[j]){
					
					count++;
				}
				i++;
				
				if(count==small.length()){
					arr.push_back(i-small.length());
				}
				
			}
			count=0;
		}
	}

	return arr;
}

int main(){
	string bigstr = "I liked the movie, acting in movie was great!";
	string smallstr="movie";
	vector<int> result;
	result=stringSearch(bigstr,smallstr);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}
