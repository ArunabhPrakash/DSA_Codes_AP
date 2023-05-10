#include<iostream>
#include<set>
#include<climits>
#include<vector>
using namespace std;
class Node{
	public:
		int x;
		int y;
		int dist;//cost to traverse thru it
		
		Node(int x,int y, int dist){
			this->x=x;
			this->y=y;
			this->dist = dist;
			
			
		}
};
class Compare{
	public:
		bool operator()(const Node &a,const Node &b){
			return a.dist<=b.dist;//help in selecting min cost dist
		}
};
int shortest_path(vector<vector<int>> grid){
	//return shortest path len
	int m = grid.size();
	int n = grid[0].size();
	
	int i=0;
	int j=0;
	//2d to denote each cell
	vector<vector<int>> dist(m+1,vector<int>(n+1,INT_MAX));
	dist[i][j]=grid[0][0];
	
	set<Node,Compare> s;// to get min dist
	s.insert(Node(0,0,dist[0][0]));
	int dx[]= {0,0,1,-1};
	int dy[]= {1,-1,0,0};//all directions where ij can move
	
	while(!s.empty()){
		auto it = s.begin();
		int cx = it->x;//took all its val
		int cy = it->y;
		int cd = it->dist;
		s.erase(it);
		//update nbrs
	for(int k=0;k<4;k++){
		int nx= cx+dx[k];
		int ny= cy+dy[k];
		if(nx>=0 and nx<m and ny>=0 and ny<n and cd+grid[nx][ny]<dist[nx][ny]){//select this if relaxes the node
			//remove the old node with old and farther distance
			Node temp(nx,ny,dist[nx][ny]);
			if(s.find(temp)!=s.end()){
				s.erase(s.find(temp));//removed
			}
			//insert new node in set
			int nd= grid[nx][ny]+cd;
			dist[nx][ny] = nd;
			s.insert(Node(nx,ny,nd));//new dist updated for a node, if can be achieved in smaller time
		}
	}
	}
	
	return dist[m-1][n-1];
}
//build main, tested, working in udemy compiler


