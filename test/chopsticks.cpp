#include<iostream>
#include<vector>
using namespace std;

int pairSticks(vector<int> length, int D)
{
	
	int N=length.size();
 	int numpairs = 0;
	for ( int i = 0; i < N; ){
		if (length[i] >= length[i+1] -D){
		numpairs++,         
        i += 2;
   
		}  
        else
        i++; 
	}
          
    return numpairs;
    
}

int main(){
	vector<int> arr={1,3,3,9,4};
	int D=2;
	cout<<pairSticks(arr,D);
}
