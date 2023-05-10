#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Car{
	public:
		string id;
		int x,y;
		Car(string id,int x,int y){
			this->id=id;
			this->x=x;
			this->y=y;
		}
		int dist() const{
			return x*x + y*y;//sq of dist
		}
		
};

class CarCompare{
	public:
	bool operator()(const Car A,const Car B){
		return A.dist() < B.dist();
	}
};
bool distCompare(Car A,Car B){
		return A.dist()<B.dist();
}
void printNearestCars(vector<Car> cars,int k){
	priority_queue<Car,vector<Car>,CarCompare> max_heap(cars.begin(),cars.begin()+k);//thats how you pass data during intialization
	for(int i=k;i<cars.size();i++){
		auto car = cars[i];//auto used to declare variable type automatically from initializer
		if(car.dist()<max_heap.top().dist()){
			max_heap.pop();
			max_heap.push(car);//you dont need to heapify, inbuilt STL 
		}
	}
	vector<Car> output;
	while(!max_heap.empty()){
		output.push_back(max_heap.top());
		max_heap.pop();
	}
	sort(output.begin(),output.end(),distCompare);
	for(auto car:output){
		cout<<car.id<<endl;
	}
	return;
}

int main(){
	int N,K,x,y;
	cin>>N>>K;
	string id;
	vector<Car> cars;
	for(int i=0;i<N;i++){
		cin>>id>>x>>y;
		Car car(id,x,y);
		cars.push_back(car);
	}
	printNearestCars(cars,K);
	return 0;
}
