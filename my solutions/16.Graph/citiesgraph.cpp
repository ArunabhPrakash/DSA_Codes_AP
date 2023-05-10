#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
	public:
		string name;//needed name thats why node created else only graph class with array of LL
		list<string> nbrs;
		
		Node(string name){
			this->name=name;//when both have same name , this is used to point to object's datamem
		}
};

class Graph{
	//allnodes
	//hashmap to access address of node
	unordered_map<string,Node*> m;
	
	public:
		Graph(vector<string> cities){
			for(auto city : cities){
				m[city]= new Node(city);
			}
		}
		
		void addEdge(string x,string y,bool undir=false){
			m[x]->nbrs.push_back(y);
			if(undir){
				m[y]->nbrs.push_back(x);
			}
		}
		void printAdjList(){
			for(auto cityPair: m){
				auto city = cityPair.first;
				Node *node = cityPair.second;
				cout<<city<<"->";
				for(auto nbr:node->nbrs){
					cout<<nbr<<",";
				}
				cout<<endl;
			}
		}

};

int main(){
	vector<string> cities = {"Delhi","London","Paris","New York"};
	Graph g(cities);
	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New york");
	g.printAdjList();
}

