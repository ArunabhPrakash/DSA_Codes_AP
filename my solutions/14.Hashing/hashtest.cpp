#include<iostream>
#include "hashtable.h"
using namespace std;

int main(){
	Hashtable<int> h;
	h.insert("Mango",100);
	h.insert("Apple",200);
	h.insert("Banana",300);
	h.insert("Orange",400);
	h.insert("guava",500);
	h.insert("licchi",600);
	h.insert("ber",700);
	h.insert("pineapple",800);
	
	h.print();
	string fruit;
	cin>>fruit;
	int *price=h.search(fruit);
	if(price!=NULL){
		cout<<"price of fruit is"<<*price<<endl;
	}
	else{
		cout<<"Fruit is not present";
	}
	
	h["newfruit"]=200;
	cout<<"\nNew fruit cost : "<<h["newfruit"]<<endl;
	h["newfruit"]+=20;
	cout<<"\nNew fruit cost : "<<h["newfruit"]<<endl;
	return 0;
	
}
