#include<iostream>

using namespace std;
    int mySqrt(int x) {
     long unsigned int max=0;
     for(long unsigned int i=0;i<=x;i++){
         if(i*i>x){
             break;
         }
         max=i;
     }
     return max;   
    }


int main(){
	cout<<mySqrt(16);	
}
