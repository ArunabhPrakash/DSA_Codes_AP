#include<iostream>
#include<vector>
using namespace std;
//working :tested in udemy compiler

void dfs(vector<vector<int>> matrix,vector<vector<bool>> &visited,vector<vector<int>> &cache,int i,int j,int m,int n){
visited[i][j] = 1;//cache here is dp
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};	

int cnt = 0;
for(int k=0;k<4;k++){
	int nx = i + dx[k];
	int ny = j + dy[k];
if( nx>=0 and ny>=0 and nx<m and ny<n and matrix[nx][ny]>matrix[i][j]){
	int subProblemCnt = 0;
	if(visited[nx][ny]){//if visited then use cache/dp
		cnt = max(cnt,1+cache[nx][ny]);
	}
	else{
		dfs(matrix,visited,cache,nx,ny,m,n);
		cnt = max(cnt,1+cache[nx][ny]);
	}
}
}
cache[i][j] = cnt;
return;

}

int longestPathSequence(vector<vector<int>> matrix){
	//code
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<bool>> visited(m+1,vector<bool>(n+1,0));
	vector<vector<int>> cache(m+1,vector<int>(n+1,0));
	// dfs from every cell
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			dfs(matrix,visited,cache,i,j,m,n);// nt return val since already stored in cache and cache passed as reference
			ans = max(ans,cache[i][j]);
		}
	}
	return ans+1;//since min size atleast 1 of any path
}

