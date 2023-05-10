#include<iostream>
#include"data_model.h"
#include<vector>
using namespace std;

vector<Product> allProduct = {
	Product(1,"apple",26),
	Product(3,"mango",16),
	Product(2,"guava",36),
	Product(4,"strawberry",29),
	Product(6,"pineapple",20),
	Product(5,"banana",56)
};

Product* chooseProd(){
	string productlist;
	cout<<"available product "<<endl;
	for(auto product:allProduct){//using linear search becasue already complexity O(n)
		productlist.append(product.getDisplayName());
	}
	cout<<productlist<<endl;
	cout<<"-------------"<<endl;
	string choice;
	cin>>choice;
	for(int i=0;i<allProduct.size();i++){
		if(allProduct[i].getShortName()==choice){
			return &allProduct[i];
		}
	}
	cout<<"Product not found!"<<endl;
	return NULL;
}
bool checkout(Cart &cart){
	if(cart.isEmpty()){
		return false;
	}
	int total=cart.getTotal();
	cout<<"pay in cash";
	int paid;
	cin>>paid;
	if(paid>=total){
		cout<<"Change"<<paid-total<<endl;
		cout<<"Thank you for shopping with us";
		return true;
	}
	else{
		cout<<"not enough cash";
		return false;
	}
	
}
int main(){
char action;
Cart cart;
while(true){
	cout<<"select action- (a)dd item,(v)iew item,(c)heckout"<<endl;
	cin>>action;
	if(action=='a'){
		Product* product=chooseProd();
		if(product!=NULL){
			cout<<"Added to the cart"<<product->getDisplayName()<<endl;
			cart.addProduct(*product);
		}
	}
	else if(action=='v'){
		cout<<"------------"<<endl;
		cout<<cart.viewCart();
		cout<<"------------"<<endl;
	}
	else{
		cart.viewCart();
		if(checkout(cart)){
			break;
		}
	}
}
}
