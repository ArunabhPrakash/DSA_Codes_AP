#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> &arr){//tested in PNG compiler
    unordered_set<int> row;
    unordered_set<int> col;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(arr[i][j]==0){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(row.find(i)!=row.end() or col.find(j)!=col.end()){
                arr[i][j]=0;
            }
        }
    }
    return arr;
    
}
int main(){
	
}
