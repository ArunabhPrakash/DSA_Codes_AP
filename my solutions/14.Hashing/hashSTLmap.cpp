#include<iostream>
#include<map>//prints in order, time becomes O(logN)
using namespace std;

int main(){
	map<string,int> menu;
	menu["maggi"]=15;
	menu["colddrink"]=20;
	menu["dosa"]=99;
	menu["dosa"]=2*menu["dosa"];
	string item;
	cin>>item;
	if(menu.count(item)==0){//search
		cout<<item<<" not available";
		
	}
	else{
		cout<<item<<"available,price: "<<menu[item];
	}
	menu.erase("dosa");
	for(auto item:menu){
		cout<<item.first<<"-"<<item.second;
	}
}
