#include<iostream>
#include<string.h>
using namespace std;

class Product{
	int id;//4 byte
	char *name;//100 bytes
	int mrp;//4
	int selling_price;//4
	public:
		Product(){
			cout<<"inside constr";
		}
		Product(int id,char *n,int mrp,int selling_price){
			this->id =id;
			this->mrp=mrp;
			this->selling_price=selling_price;
			name = new char[strlen(n)+1];
			strcpy(name,n);
		}
		Product(Product &x){
			id=x.id;
			name = new char[strlen(x.name)+1];
			mrp=x.mrp;
			selling_price=x.selling_price;
			strcpy(name,x.name);
		}
		void operator=(Product &x){
			id=x.id;
			name = new char[strlen(x.name)+1];
			mrp=x.mrp;
			selling_price=x.selling_price;
			strcpy(name,x.name);
		}
	void setMRP(int price){
		mrp = price;
	}
	void setSellingPrice(int price){
		if(price>mrp){
			selling_price=mrp;
		}
		else
			selling_price = price;
	}
	int getMRP(){
		return mrp;
	}
	int getSellingPrice(){
		return selling_price;
	}
	void showDetails(){
		cout<<"Name : "<<name<<endl;
		cout<<"ID : "<<id<<endl;
		cout<<"Selling price : "<<selling_price<<endl;
		cout<<"MRP : "<<mrp<<endl;
	}
	void setName(char *name){
		strcpy(this->name,name);
	}
	~Product(){
		cout<<" Deleting "<<name<<endl;
		if(name!=NULL){
			delete [] name;	
			name = NULL;
		}
		
		
	}
};

int main(){
	Product camera(101,"GoProHero9",28000,26000);
	camera.showDetails();
	Product oldcam(camera);
	oldcam.setName("goPro8");
	oldcam.showDetails(); 
	Product webcam(camera);//copy constructor, can also override by writing func Product(Product &z)
	webcam.showDetails();
	Product handycam=camera;//also calls copy constructor
	handycam.showDetails();
	Product assignment_op_camera;
	assignment_op_camera = camera;//copy assignment operator:creates shallow copy
	assignment_op_camera.showDetails();
	//cout<<sizeof(camera)<<endl<<"MRP "<<camera.getMRP()<<endl<<"SELLING PRICE"<<camera.getSellingPrice();
	
	
}
