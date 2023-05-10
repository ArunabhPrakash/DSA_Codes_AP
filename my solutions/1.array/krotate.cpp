#include<bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k){
    // your code  goes here
    vector<int> b = a;
    for(int i=0;i<a.size();i++){
        if(i-k<0)
        a[i] = b[a.size()+i-k];
        else{
            a[i]=b[i-k];
        }
        
    }
    return a;
}
