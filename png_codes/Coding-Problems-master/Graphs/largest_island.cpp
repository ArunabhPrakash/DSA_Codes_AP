#include<iostream>
#include<vector>
using namespace std;
//working
int dfs(vector<vector<int>> &matrix,vector<vector<bool>> &visited,int i,int j,int m,int n){
	visited[i][j] = true;
	int cs = 1;
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};
	
	for(int k=0;k<4;k++){
		int nx = i + dx[k];
		int ny = j + dy[k];
		
		if(nx>=0 and nx<m and ny>=0 and ny<n and matrix[nx][ny]==1 and !visited[nx][ny] ){
		int subcomponent = dfs(matrix, visited,nx,ny,m,n);//dfs call on all valid
		cs += subcomponent;	
		}
		
	}
	return cs;
}

int largest_island(vector<vector<int>> matrix){
	int m = matrix.size();
	int n = matrix[0].size();
	//visited matrix
	vector<vector<bool>> visited(m,vector<bool>(n,false));
	
	int largest = 0;
	
	for(int i=0;i<m;i++){//call on each block of grid
		for(int j=0;j<n;j++){
			if(!visited[i][j] and matrix[i][j]==1){//both 1 and need to be unvisited
				int size = dfs(matrix,visited,i,j,m,n);
				if(size>largest){
					largest = size; // comparing all islands
				}
			}
		}
	}
	return largest;
}

int main(){
	vector<vector<int>> grid = {{1,0,0,1,0},{1,0,1,0,0},{0,0,1,0,1},{1,0,1,1,1},{1,0,1,1,0}};
	cout<<largest_island(grid)<<endl;
	return 0;
}
