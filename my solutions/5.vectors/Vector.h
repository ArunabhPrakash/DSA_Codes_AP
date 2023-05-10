template<typename T>//data in this class will be of type T
class Vector{
	//data members
	T *arr;
	int cs;//current size
	int ms;//max size
	
public:
	Vector(int max_size=1){
		cs=0;
		ms=max_size;
		arr = new T[ms];
		
	}
	void push_back(T d){
		//Two cases
		if(cs==ms){
			//create a new aray and delete the old one, double the capacity
			T *oldArr=arr;
			ms=2*ms;
			arr= new T[ms];
			for(int i=0;i<cs;i++){
				arr[i]=oldArr[i];
			}
			delete [] oldArr;
		}
		arr[cs] = d;
		cs++;
	}
	void pop_back(){
		if(cs>=0){
		cs--;	
		}
		
	}
	bool isEmpty(){
		return cs==0;
	}
	T front() const{
		return arr[0];
	}
	T back() const{
		return arr[cs-1];
	}
	int at(int i) const{
		return arr[i];
	}
	int size() const{//const used if data member is not changed helps in debugging
		return cs;
	}
	int capacity() const{
		return ms;
	}
	T operator[](const int i) const{
		return arr[i];//operator overloading
	}
	
};

