#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>//for int max but working w/o that as well
using namespace std;
class Node{
	public:
		int d;
		Node *left;
		Node *right;
		
		Node(int data){
			d=data;
			left=NULL;
			right=NULL;
		}
};

Node* buildTree(){
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	Node *n=new Node(d);
	n->left=buildTree();
	n->right=buildTree();
	return n;
}
void preorder(Node *root){
	if(root==NULL){
		return;
	}
	cout<<root->d;
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(Node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->d;
	inorder(root->right);
}
void postorder(Node *root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->d;
}

void levelorder(Node *root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* t=q.front();
		q.pop();
		if(t==NULL){
			cout<<"\n";
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<t->d<<"\t";
			if(t->left)
			q.push(t->left);
			if(t->right)
			q.push(t->right);
		}
		
	}
}

Node* levelorderBuild(){
	int d;
	cin>>d;
	Node *root=new Node(d);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *t=q.front();
		q.pop();
		int left;
		cin>>left;
		if(left!=-1){
			Node *leftn=new Node(left);
			t->left=leftn;
			q.push(leftn);
		}
		int right;
		cin>>right;
		if(right!=-1){
			Node *rightn=new Node(right);
			t->right=rightn;
			q.push(rightn);
		}
		
	}
	return root;
}
int height(Node *root,int n){
	if(root==NULL){
		return n;
	}
	else{
		
	int left=n;
	int right=n;
		if(root->left!=NULL){
			left=height(root->left,n+1);
		}
		if(root->right!=NULL){
			right=height(root->right,n+1);
		}
		return max(left,right);
	}
}

int diameter(Node *root){//it is no of max nodes b/w two nodes
	if(root==NULL){
		return 0;
	}
	int D1= height(root->left,0)+height(root->right,0)+1;//mine one is correct
	int D2= diameter(root->left);
	int D3= diameter(root->right);
	return max(D1,(max(D2,D3)));
}
vector<int> printKthLevel(Node* root, int k){ //working: ide tested
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
			ans.push_back(t->d);
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
		sum+=t->d;
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
    if (root1 && root2 && root1->d == root2->d)
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
	v.push_back(root->d);
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
			if(sum+root->d==targetSum){
				path.push_back(root->d);
				ans.push_back(path);
			}
		return ans;
		}
		else{
			sum=sum+root->d;
			path.push_back(root->d);
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
	int sum=0,val=root->d;
	sum+=descendantSum(root->left);
	sum+=descendantSum(root->right);
	val+=sum;
	if(sum!=0)
	root->d=sum;
	return val;
}

bool heightBalBT(Node *root){
	if(root==NULL){
		return true;
	}
	int left=0;
	int right=0;
	int result;
	if(heightBalBT(root->left) && heightBalBT(root->right)){
		if(root->left)
		left=height(root->left,1);
		if(root->right)
		right=height(root->right,1);
		result=left-right;
		if(result>=-1 && result<=1)
		return true;
	}
	return false;
}

pair<int, int> maxSumHelper(Node *root)
{
    if (root==NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> sum1 = maxSumHelper(root->left);
    pair<int, int> sum2 = maxSumHelper(root->right);
    pair<int, int> sum;
 
    // This node is included (Left and right children
    // are not included)
    sum.first = sum1.second + sum2.second + root->d;
 
    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(sum1.first, sum1.second) +
                 max(sum2.first, sum2.second);
 
    return sum;
}
 
int maxSum(Node *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}
int main(){
//	Node *root = buildTree();
	Node *root = levelorderBuild();
	vector<int> ans,iOdVec;
	vector<vector<int>> result;
	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	postorder(root);
	cout<<"\n";
	levelorder(root);
	cout<<"\n"<<height(root,0);
	cout<<"\n"<<diameter(root)<<"\n";//w/o source and end node
	ans=printKthLevel(root,3);//starts at 1
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n"<<sumBT(root);
	cout<<"\n"<<minDepth(root);//starts at 1
	cout<<"\n"<<isSymmetric(root)<<"\n";
//	iOdVec=removeHalfNodes(root); //commented out because after deleting, might be prob in BT to do another run(update: still working fine)
//		for(int i=0;i<iOdVec.size();i++){
//		cout<<iOdVec[i]<<" ";
//	}
//	
//	result = pathSum(root,22);//same reason for commenting out as RHN
//	for(int i=0;i<result.size();i++){
//		cout<<"[";
//		for(int j=0;j<result[i].size();j++){
//			cout<<result[i][j]<<" ";
//		}
//		cout<<"],";
//	}
//	descendantSum(root);
//	levelorder(root);
	cout<<"\n"<<heightBalBT(root);
	levelorder(root);
	cout<<maxSum(root);
}
