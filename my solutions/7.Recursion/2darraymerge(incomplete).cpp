#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> mergeC(int sr,int er,int sc,int ec,vector<vector<int>> v){
	int mid=(sc+ec)/2;
	int i=sc;
	int j=mid+1;
	vector<vector<int>> temp;
	while(i<=mid and j<=ec){
		if(v[sr][i]<v[sr][j]){
			temp[sr].push_back(v[sr][i]);
			
		}
		else{
			temp[sr].push_back(v[sr][j]);
			
		}
	}
	while(i<=mid){
		temp[sr].push_back(v[sr][i]);
		
	}
	while(j<=ec){
		temp[sr].push_back(v[sr][j]);
		
	}
	for(int i=sc;i<=ec;i++){
		v[sr][i]=temp[sr][i];
	}
	return v;
}
vector<vector<int>> mergeR(int sr,int er,int sc,int ec,vector<vector<int>> v){
	int mid=(sr+er)/2;
	int i=sr;
	int j=mid+1;
	int k=sr;
	vector<vector<int>> temp;
	while(i<=mid and j<=er){
		if(v[i][sc]<v[j][sc]){
			temp[k][sc]=v[i][sc];
			k++;
		}
		else{
			temp[k][sc]=v[j][sc];
			k++;
		}
	}
	while(i<=mid){
		temp[k][sc]=v[i][sc];
		k++;
	}
	while(j<=er){
		temp[k][sc]=v[j][sc];
		k++;
	}
	for(int i=0;i<=er;i++){
		v[i][sc]=temp[i][sc];
	}
	return v;
}
vector<vector<int>> mergeS(int sr,int er,int sc,int ec,vector<vector<int>> v){
	if(sr>=er or sc>=ec){
		cout<<"sr:"<<sr<<","<<"er:"<<er<<endl;
		return v; 
	}
	int midr=(sr+er)/2;
	int midc=(sc+ec)/2;
	cout<<midr<<","<<midc<<endl;
	v=mergeS(sr,midr,sc,midc,v);
	v=mergeS(midr+1,er,midc+1,ec,v);
	for(int i=sr;i<=er;i++){
		v=mergeR(i,er,sc,ec,v);
	}
	for(int i=sc;i<=ec;i++){
		v=mergeC(sr,er,i,ec,v);
	}
	
	return v;
	
}
vector<vector<int>> mergeSort(int m, int n, vector<vector<int>> v){
    int sr=0;
    int er=m-1;
    int sc=0;
    int ec=n-1;
    v=mergeS(sr,er,sc,ec,v);
    return v;
}

int main(){
	vector<vector<int>> arr={{18,4,16,8},{23,13,20,11},{28,24,26,25},{1,30,15,19}};
	int m=4;
	int n=4;
	vector<vector<int>> v;
	v=mergeSort(m,n,arr);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

