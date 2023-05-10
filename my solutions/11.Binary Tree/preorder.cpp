#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>//for int max but working w/o that as well
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

void printInorder(Node *root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

void printPostorder(Node *root){
	if(root==NULL){
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}
void levelOrderPrint(Node *root){//need to take root in all cases except build and return only when you modify or create tree
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node *temp= q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
			
		}
	}
}


Node* levelOrderBuild(){
int d;
cin>>d;
Node* root = new Node(d);
queue<Node*> q;
q.push(root);
while(!q.empty()){
	Node* current = q.front();
	q.pop();
	int c1,c2;
	cin>>c1>>c2;
	if(c1!=-1){
		current->left = new Node(c1);
		q.push(current->left);
	}
	if(c2!=-1){
		current->right = new Node(c2);
		q.push(current->right);
	}
}
return root; 
}

int height(Node*root){//this is returning level not height, level starts frm 1, height frm 0
	if(root==NULL){
		return 0;
	}
	int h1=height(root->left);
	int h2=height(root->right);
	return (1 + max(h1,h2));
}
int diameter(Node *root){//it is no of max edges b/w two nodes, gfg shows: max nodes b/w two nodes
	if(root==NULL){
		return 0;
	}
	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);
	
	return (max(D1,max(D2,D3)));
}
class HDPair{
	public:
		int height;
		int diameter;
		
};

HDPair optDiameter(Node*root){
	HDPair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}
	HDPair Left = optDiameter(root->left);
	HDPair Right = optDiameter(root->right);
	p.height = max(Left.height,Right.height)+1;//in this only one recursive call for both height and diameter while in normal seperate calls
	int D1 = Left.height + Right.height;//for height and diameter
	int D2 = Left.diameter;
	int D3 = Right.diameter;
	
	p.diameter = max(D1,max(D2,D3));
	return p;
}
vector<int> printKthLevel(Node* root, int k){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int level=1;
	vector<int> ans;
	while(!q.empty()){
		Node* t=q.front();
		q.pop();
		if(t==NULL){
			level++;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			if(level==k)
			ans.push_back(t->data);
			if(t->left)
			q.push(t->left);
			if(t->right)
			q.push(t->right);
		}
		
	}
	return ans;
  
}
int sumBT(Node* root)//working : ide tested
{	int sum=0;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* t=q.front();
		q.pop();
		sum+=t->data;
			if(t->left)
			q.push(t->left);
			if(t->right)
			q.push(t->right);
		
	}
	return sum;
}
int depthhelper(Node *root,int d,int minD){
	if(root==NULL){
		return d;
	}
	else{
		int left=INT_MAX;
		int right=INT_MAX;
		if(root->left==NULL and root->right==NULL){
			return min(minD,d);
		}
		if(root->left)
		left=depthhelper(root->left,d+1,minD);
		if(root->right)
		right=depthhelper(root->right,d+1,minD);
		return min(minD,min(left,right));
		
	}
}
int minDepth(Node *root) {
       int minD=INT_MAX;
	   minD=depthhelper(root,1,minD);
	   return minD;
	   
}

bool isMirror(struct Node* root1, struct Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);
    return false;
}
 
bool isSymmetric(struct Node* root)
{
    return isMirror(root, root);
}

Node* RHN(Node *root){
	
   if(root->left!=NULL && root->right==NULL){
 		Node *temp = root;
 		root=root->left;
 		delete temp;	
 		root=RHN(root);
 		return root;
   }
   else if(root->left==NULL && root->right!=NULL){
   		Node *temp = root;
 		root=root->right;
 		delete temp;
 		root=RHN(root);
 		return root;
   }
   else if(root->left!=NULL && root->right!=NULL){
   		
		root->left=RHN(root->left);
   		root->right=RHN(root->right);
   		return root;
   }
   else{
   	
   	return root;
   }
   
 	
}
vector<int> inorderVector(Node *root,vector<int> v){
	if(root==NULL){
		return v;
	}
	v=inorderVector(root->left,v);
	v.push_back(root->data);
	v=inorderVector(root->right,v);
	return v;
}
vector<int> removeHalfNodes(Node *root)
{
	vector<int> v;
	root=RHN(root);
	v=inorderVector(root,v);
	return v;
} 
vector<vector<int>> calcSum(Node* root,int targetSum,vector<int> path,vector<vector<int>> ans,int sum){
		if(root->left==NULL && root->right==NULL){
			if(sum+root->data==targetSum){
				path.push_back(root->data);
				ans.push_back(path);
			}
		return ans;
		}
		else{
			sum=sum+root->data;
			path.push_back(root->data);
			if(root->left){
				ans=calcSum(root->left,targetSum,path,ans,sum);	
			}
			if(root->right){
				ans=calcSum(root->right,targetSum,path,ans,sum);
			}
			
			return ans;
		}
	
	
}
vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<vector<int>> ans;
    vector<int> path;
    ans=calcSum(root,targetSum,path,ans,0);
    return ans;
}

int descendantSum(Node *root){
	if(root==NULL){
		return 0;
	}
	int sum=0,val=root->data;
	sum+=descendantSum(root->left);
	sum+=descendantSum(root->right);
	val+=sum;
	if(sum!=0)
	root->data=sum;
	return val;
}
void heightdisp(Node *root){
	cout<<"height ";
	int h=height(root);
	if(h==0)
	cout<<"0";
	else
	cout<<h-1;
}
int main(){
	//Node * root = buildTree();//buidtree has same return type
	Node *root =levelOrderBuild();
	printPreorder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPostorder(root);
	cout<<endl;
	levelOrderPrint(root);
	cout<<endl;
	cout<<"diameter "<<diameter(root)<<endl;
	cout<<"Opt diameter "<<optDiameter(root).diameter<<endl;
	heightdisp(root);
	
	
	return 0;
}

