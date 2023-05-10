#include<iostream>
#include<vector>
using namespace std;

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
   int row=v.size();
 
   int col=v[0].size();
 
   int M[row][col];
   for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i==0 and j==0){
				M[i][j]=v[i][j];
				
			}
			else if(i==0 and j!=0){
				M[i][j]=v[i][j]+M[i][j-1];
			
			}
			else if(j==0 and i!=0){
				M[i][j]=v[i][j]+M[i-1][j];
				
			}
			else{
				M[i][j]=v[i][j] + M[i-1][j] + M[i][j-1] - M[i-1][j-1];
				
			}
		
		}
		
    
	}
	int sum=0;
	if(sr-1>=0 and sc-1>=0){
		 sum = M[er][ec]-M[er][sc-1]-M[sr-1][ec]+M[sr-1][sc-1];
	}
	else if(sr-1<0 and sc-1>=0){
		sum = M[er][ec]-M[er][sc-1];
	}
	else if(sr-1>=0 and sc-1<0){
		sum = M[er][ec]-M[sr-1][ec];
	}
	else{
		sum=M[er][ec];
	}
	
	return sum;
}

int main(){
	vector<vector<int>> v ={{1,2,3,4,6},{5,3,8,1,2},{4,6,7,5,5},{2,4,8,9,4}};
	int sr=1;
	int sc=2;
	int er=3;
	int ec=3;
	cout<<sum(v,sr,sc,er,ec);
}
