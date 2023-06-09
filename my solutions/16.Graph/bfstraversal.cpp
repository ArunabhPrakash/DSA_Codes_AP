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
	void bfs(int source){
			queue<int> q;
			bool *visited= new bool[V]{0};//v many ptrs(array of ptrs) created with val 0
			q.push(source);
			visited[source]=true;
			while(!q.empty()){
				int f= q.front();
				cout<<f<<endl;
				q.pop();
				for(auto nbr:l[f]){
					if(!visited[nbr]){
						q.push(nbr);
						visited[nbr]=true;// we set visited true before even visitng, if we dont do that, queue filled with redundant val
					}
				}
			}
		}
	void dfsHelper(int node,bool *visited){//visted pointer will point at same loc as visited in dfs but it is not call by ref
		visited[node]=true;
		cout<<node<<",";
		for(int nbr:l[node]){
			if(!visited[nbr]){
				dfsHelper(nbr,visited);
			}
		}
		return;
	}
	
	void dfs(int source){
		bool *visited = new bool[V]{0};
		dfsHelper(source,visited);
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
	g.dfs(1);//can start from anywhere

	return 0;
}

