#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

string concatenate(vector<int> numbers){
    int n=numbers.size();
    vector<int> ones,others,final;
	for(int i=0;i<n;i++){
    	if(numbers[i]<10){
    		ones.push_back(numbers[i]);
		}
		else{
			others.push_back(numbers[i]);
		}
	}
	sort(ones.begin(),ones.end(),greater<int>());
	sort(others.begin(),others.end(),greater<int>());
	int j=0;
	int k=0;
	while(j<ones.size() or k<others.size()){
		if(ones[j]>=others[k]/10){
			final.push_back(ones[j]);
			j++;
		}
		else{
			final.push_back(others[k]);
			k++;
		}
	}
	if(j==ones.size()){
		while(k<others.size()){
			final.push_back(others[k]);
			k++;
		}
	}
	else{
		while(j<ones.size()){
			final.push_back(ones[j]);
			j++;
		}
	}
	string op;
	for(int i=0;i<n;i++){
		string temp=to_string(final[i]);
		op+=temp;	
	}
	return op;
	
	
		
}

int main(){
	vector<int> num={100,11,20,30,3};
	cout<<concatenate(num);
}
