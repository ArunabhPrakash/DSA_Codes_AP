#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
	unordered_map<string,unordered_map<string,int>> m;//initialize
	m["pizza"]["margharita"]=10;//insert
	m["pizza"]["cheeseburst"]=20;
	m["pizza"]["farmhouse"]=30;
	m["burger"]["Mcalootikki"]=10;
	m["burger"]["Mcmaharaja"]=20;
	
	cout<<"Pizza Margharita: "<<m["pizza"]["margharita"]<<"\n";//single line cout/search
	
	for(auto i:m){
		cout<<"Type: "<<i.first;
		for(auto j:i.second){
			cout<<" food name: "<<j.first<<" Price:"<<j.second<<"\n";//cout through loop, iterate over all 
		}
	}
}
