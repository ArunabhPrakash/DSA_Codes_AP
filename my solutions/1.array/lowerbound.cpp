#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> A, int Val) {
    // your code goes here(running tested)
    int dif=INT_MAX;
    int lBval=-1;
    for(long unsigned int i=0;i<A.size();i++){
        if(A[i]==Val){
            return Val;
        }
        if(A[i]<Val){
        int newdif=Val-A[i];
        if(newdif<dif){
            dif=newdif;
            lBval = A[i];
        }    
        }
        
    }
    return lBval;
}
