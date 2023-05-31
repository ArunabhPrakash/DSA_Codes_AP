#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int d){
			data =d;
			left=right=NULL;
		}
};

Node* buildTree(){//returns Node pointer like some func returns int, as unlike stack it doesnt have cmnd to get head directly
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	Node* n = new Node(d);
	n->left = buildTree();//tree will build in preorder
	n->right = buildTree();
	return n;
}

void printPreorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}
vector<int> getTopViewHelper(Node *root){
	//use ordered_map (Working) for each vertical height,have pair of val and level, choose min level
	map<int,pair<int,int>> m;
	vector<int> final;
	queue<pair<Node*,int>> q;
	q.push({root,0});
	q.push({NULL,0});
	int level=0;
//	Node *t = q.front();
//	cout<<"\n data of queue "<<t->data;
//	q.pop();
//	t=q.front();
//	if(t==NULL){
//		cout<<"\nisnull";
//	}
//	q.pop();
//	q.push(root);
//	q.push(NULL);
	while(q.empty()==false){
		
		pair<Node*,int> t2 = q.front();
		Node* temp=t2.first;
		int V_height=t2.second;
		q.pop();
		if(temp==NULL){//if null and not empty then increase level
			if(!q.empty()){
				level++;
				q.push({NULL,0});	
				cout<<"\nadded null and increased level to "<<level;
			}
			else{
				cout<<"\nQueue empty";
			}
		}
		else{//else if not in map then add else check if level of earlier stored bigger then store this one
			int d = temp->data;
			cout<<"\nentered else for "<<d;
			if(m.find(V_height)==m.end()){
				m[V_height]={d,level};
				cout<<"\nadded newly to map "<<d;
				if(temp->left!=NULL){
					q.push({temp->left,V_height-1});
					cout<<"\npushed left: "<<temp->left->data;
				}
				if(temp->right!=NULL){
					q.push({temp->right,V_height+1});
					cout<<"\npushed right: "<<temp->right->data;
				}
			}
			else{
				int curr_VH = m[V_height].second; 
				if(curr_VH>level){
					m[V_height]={d,level};
				}
				if(temp->left!=NULL){
					q.push({temp->left,V_height-1});
				}
				if(temp->right!=NULL){
					q.push({temp->right,V_height+1});
				}
			}
		}
		cout<<"\nthis while completed";
	}
	int k =0;
	cout<<"reached k\nchecking map in asc order";
	for(auto i:m){
		pair<int,int> temp = i.second;
		cout<<temp.first;
		final.push_back(temp.first);
	}
	return final;
}

vector<int> getTopView(Node *root) {
    return getTopViewHelper(root);
}
int main(){
	Node* root =buildTree();
	printPreorder(root);
	vector<int> arr = getTopView(root);
	cout<<endl;
	for(auto i:arr){
		cout<<i<<" ";
	}
}
