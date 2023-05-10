#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph{
	int V;
	list<pair<int,int>> *l;
public:
	Graph(int v){
		V=v;
		l=new list<pair<int,int>> [V];//an array of linked list of value pair
	}
	
	void addEdge(int u,int v,int wt,bool undir=true){
		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}
	int dijkstra(int src,int dest){
		 vector<int> dist(V,INT_MAX);//will be returned finally dist[dest]
		 set<pair<int,int>> s;
		 dist[src]=0;
		 s.insert({0,src});//source pushed in set s
		 
		 while(!s.empty()){
		 	auto it=s.begin();
		 	int node=it->second;//node contains src
		 	int distTillNow = it->first;
		 	s.erase(it);
		 	for(auto nbrPair:l[node]){//all edges iteration of a vertexx
		 		int nbr = nbrPair.second;
		 		int currentEdge = nbrPair.first;//contains weight(WT)
		 		if(distTillNow + currentEdge <dist[nbr]){//earlier all dist set int_max so value will be relaxed
		 			//remove if already exist in set
					auto f= s.find({dist[nbr],nbr});
					if(f!=s.end()){//if exist already so prevent duplicate by deleting first
						s.erase(f);
					}
					 dist[nbr]=distTillNow+currentEdge;//if new dist is less than older dist so insert this
		 			s.insert({dist[nbr],nbr});//curly brackets is make pair
				 }
			 }
			
		 }
		  for(int i=0;i<V;i++){
			 	cout<<"Node "<<i<<" Dist "<<dist[i]<<endl;
			 }
		 return dist[dest];
	}
};

int main(){
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);
	cout<<g.dijkstra(0,4)<<endl;
	
}
