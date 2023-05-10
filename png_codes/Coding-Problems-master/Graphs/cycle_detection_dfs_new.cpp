#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int v){
		V=v;
		l = new list<int>[V];//created LL array of size of V
	}
	void addEdge(int i,int j,bool undir=true){
		l[i].push_back(j);//added in LL of i
		if(undir){
			l[j].push_back(i);//addded in ll of j
		}
	}
	bool dfs(int node,vector<bool> &visited,int parent){
		visited[node] = true;
		for(auto nbr:l[node]){
			if(!visited[nbr]){
				bool nbrFoundACycle = dfs(nbr,visited,node);
				if(nbrFoundACycle){//if not visited then call dfs on its neighbours after visiting
					return true;
				}
			}
			else if(nbr!=parent){
				return true;
			}
			
		}
		return false;
	}
	bool contains_cycle(){
		//graph is a single component
		vector<bool> visited(V,false);
		return dfs(0,visited,-1);
	}
};

int main(){
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	/*g.addEdge(2,0);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);*/
	cout<<g.contains_cycle();
	return 0;
}

