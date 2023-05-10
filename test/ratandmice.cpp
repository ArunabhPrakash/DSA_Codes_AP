#include<iostream>
#include<vector>
using namespace std;
bool solvequiz(vector<vector<string>> &arr,vector<vector<int>> &sol,int i,int j){
	if(i==arr.size()-1 and j==arr[1].size()-1){
		sol[i][j]=1;
		return true;
	}
	else if(i<arr.size() and j<arr[1].size() and i>-1 and j>-1){
		if(arr[i][j]=="X" or sol[i][j]==1){
			return false;
		}
		else{
			sol[i][j]=1;
			if(solvequiz(arr,sol,i-1,j) or solvequiz(arr,sol,i+1,j) or solvequiz(arr,sol,i,j-1) or solvequiz(arr,sol,i,j+1)){
				return true;
			}
			else{
				sol[i][j]=0;
				return false;
			}
		}
	}
	else{
		return false;
	}
}
vector<vector<int>> ratAndMice(vector<vector<string>> arr) {
    vector<vector<int>> sol(arr.size(),vector<int> (arr[1].size(), 0));
	solvequiz(arr,sol,0,0);
	return sol;
}

int main(){
	vector<vector<string>> str={{"O","X","O","O"},{"O","O","O","X"},{"X","O","X","O"},{"X","O","O","X"},{"X","X","O","O"}};
	vector<vector<int>> sol(str.size(),vector<int> (str[1].size(), 0));
	sol=ratAndMice(str);
	for(int i=0;i<sol.size();i++){
			for(int j=0;j<sol[1].size();j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
}
