#include<iostream>
class Queue{
	int *arr;
	int cs;
	int ms;
	
	int front;
	int rear;

public:
	Queue(int default_size=5){
		ms=default_size;
		arr = new int[ms];
		front=0;
		cs=0;
		rear=ms-1;
	}
	bool full(){
		return cs==ms;
	}
	bool empty(){
		return cs==0;
	}
	void push(int data){
		if(!full()){
			rear=(rear+1)%ms;
			arr[rear]=data;
			cs++;
		}
	}
	void pop(){
		if(!empty()){
			front = (front+1)%ms;
			cs--;//just move front ++, and if something is added later to that pos then overwrite
		}
	}
	
	int frontfunc(){
		return arr[front];
	}
};
