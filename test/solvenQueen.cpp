#include<iostream>
using namespace std;

bool canplace(int board[][20],int n,int x,int y){
	for(int k=0;k<x;k++){
		if(board[k][y]==1){
			return false;
		}
	}
	int i=x;
	int j=y;
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	i=x;
	j=y;
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j++;
	}
	return true;
}

void printboard(int board[][20],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
			
		}
		cout<<endl;
	}
}

bool solveNqueen(int n,int board[][20],int i){
	if(i==n){
		printboard(board,n);
		return true;
	}
	else{
		for(int j=0;j<n;j++){
			printboard(board,n);
			cout<<endl;
			if(canplace(board,n,i,j)){
				board[i][j]=1;
				bool success=solveNqueen(n,board,i+1);
				if(success){
					return true;
				}
					board[i][j]=0;
			}
		}
		return false;
	}
}
int main(){
	int board[20][20]={0};
	int n;
	cin>>n;
	solveNqueen(n,board,0);
}
