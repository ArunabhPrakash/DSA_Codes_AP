#include<iostream>
#include<vector>
using namespace std;

void mangotrees(int arr[][6],int row,int col){
	int M[6][6];
	int x=-1;
	int y=-1;
	int total=0;
	int max_min=INT_MIN;
	vector<pair<int,int>> result;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i==0 and j==0){
				M[i][j]=arr[i][j];
				cout<<M[i][j]<<" ";
			}
			else if(i==0 and j!=0){
				M[i][j]=arr[i][j]+M[i][j-1];
				cout<<M[i][j]<<" ";
			}
			else if(j==0 and i!=0){
				M[i][j]=arr[i][j]+M[i-1][j];
				cout<<M[i][j]<<" ";
			}
			else{
				M[i][j]=arr[i][j] + M[i-1][j] + M[i][j-1] - M[i-1][j-1];
				cout<<M[i][j]<<" ";
			}
		
		}
		cout<<endl;	
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			int s1=M[i][j];
			int s2=M[i][col-1]-M[i][j];
			int s3=M[row-1][j]-M[i][j];
			int s4=M[row-1][col-1]-(s1+s2+s3);
			int s5=min(s1,s2);
			int s6=min(s3,s4);
			s6=min(s5,s6);
			max_min=max(s6,max_min);
			if(s6==max_min){
				x=i;
				y=j;
				total=s6;
				
			}
		}
	}
	
	cout<<x<<" "<<y<<":"<<total;
}
int main(){
	int arr[][6]={{0,1,1,0,0,0},{1,0,0,1,1,0},{0,1,0,0,0,0},{0,1,1,0,0,1},{1,0,0,1,1,0},{0,1,0,0,0,0}};
	int row=6;
	int col=6;
	mangotrees(arr,row,col);
	
}
