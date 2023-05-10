#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> getHashVal(string s,int i,int j){
	vector<int> freq(26,0);
	//iterate over string i to j to fill this vector
	for(int k=i;k<=j;k++){
		char ch=s[k];
		freq[ch-'a']++;
		
		
	}
	return freq;
}
int anagrams_substrings(string s){
	map<vector<int>,int> m;
	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			//substring i to j
			vector<int> h = getHashVal(s,i,j);
			//put it inside map
			m[h]++;
		}
	}
	//pairs
	int ans=0;
	for(auto p:m){
		int freq = p.second;
		if(freq>=2){
			ans += (freq)*(freq-1)/2;
		}
	}	
	return ans;
}

int main(){
	string s;
	cin>>s;
	cout<<anagrams_substrings(s);
	return 0;
}
