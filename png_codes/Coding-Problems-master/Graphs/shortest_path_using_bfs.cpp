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
	void bfs(int source,int dest){
			queue<int> q;
			bool *visited= new bool[V]{0};//v many ptrs(array of ptrs) created with val 0
			int *dist = new int[V]{0};
			int *parent = new int[V];//aim is to first find parent and then use that value to find dist to parent and add 1
			for(int i=0; i<V;i++){
				parent[i]=-1;
			}
			q.push(source);
			visited[source]=true;
			parent[source] = source;
			dist[source] = 0;
			while(!q.empty()){
				int f= q.front();
				cout<<f<<endl;
				q.pop();
				for(auto nbr:l[f]){
					if(!visited[nbr]){
						//set parent of neighbout = f
						q.push(nbr);
						parent[nbr]=f;
						dist[nbr]=dist[f]+1;//sotechnically when you push in queue, update dist at that time
						visited[nbr]=true;
					}
				}
			}
		//print shortest dist
		for(int i=0;i<V;i++){
			cout<<"Shortest dist to "<<i<<" is "<<dist[i]<<endl;
		}
		
		// print path from source to any dest
		cout<<"\nPath from source: "<<source<<" to destination: "<<dest<<endl;
		if(dest!=-1){
			int temp = dest;
			while(temp!=source){
				cout<<temp<<"--";
				temp=parent[temp];
			}
			cout<<source<<endl;
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
	g.bfs(1,5);//can start from anywhere

	return 0;
}

