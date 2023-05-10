#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

class Graph{
	list<int> *l;//if need to name verticles then create seperate class string
	int V;
public:
	Graph(int V){
		this->V=V;
		l = new list<int>[V];//created LL array of V elements, each it's own LL
		
	}
	
	void addEdge(int x,int y){
		l[x].push_back(y);//can never be undirected
		
	}
	
	void topological_sort(){
		vector<int> indegree(V,0);
		for(int i=0;i<V;i++){
			for(auto nbr:l[i]){
				indegree[nbr]++;
			}
		}
	queue<int> q;
	for(int i=0;i<V;i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
	int node = q.front();
	cout<<node<<" ";
	q.pop();
	for(auto nbr: l[node]){//very smart move, reduce indegree of nbr
		indegree[nbr]--;
		if(indegree[nbr]==0){
			q.push(nbr);
		}
	}
		
	}
	}
	
};

int main(){
	Graph g(6);
	g.addEdge(0,2);
	g.addEdge(2,3); 
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.topological_sort();
	return 0;
}

