#include<iostream>
#include<list>
#include<queue>
#include<vector>
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
	bool dfsHelper(int node,bool *visited,int destination,vector<int> q){
		visited[node]=true;
		for(int nbr:l[node]){
			if(nbr==destination){
				for(auto iter:q){
					cout<<iter<<"->";
				}
				cout<<nbr;
				return true;
			}
		}
		for(int nbr:l[node]){
			if(!visited[nbr]){
				q.push_back(nbr);
				if(dfsHelper(nbr,visited,destination,q)){
					return true;
				}
				q.pop_back();
			}
		}
		return false;
	}
	
	void dfs(int source,int destination){
		 vector<int> q;
		 q.push_back(source);
		bool *visited = new bool[V]{0};
		if(!dfsHelper(source,visited,destination,q)){
			cout<<"no route";
		}
	}
};

int main(){
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.dfs(1,6);

	return 0;
}

