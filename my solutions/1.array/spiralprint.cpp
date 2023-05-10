#include<iostream>
using namespace std;

void print(int arr[][10],int n,int m){
	int startRow =0;
	int endRow = n-1;
	int startCol=0;
	int endCol=m-1;
	//outer loop(traverse array boundary
	while(startCol<=endCol and startRow<=endRow){
		for(int col=startCol;col<=endCol;col++){//start row
			cout<<arr[startRow][col]<<" ";
		}
		for(int row=startRow+1;row<=endRow;row++){//end col
			cout<<arr[row][endCol]<<" ";
		}
		for(int col=endCol-1;col>=startCol;col--){//endrow
			if(startRow==endRow){//prevent duplicate printing
				break;
			}
			cout<<arr[endRow][col]<<" ";
		}
		for(int row=endRow-1;row>=startRow+1;row--){//start col
			if(startCol==endCol){//prevent duplicate printing
				break;
			}
			cout<<arr[row][startCol]<<" ";
		}
		startRow++;
		endCol--;
		startCol++;
		endRow--;
	}
}

int main(){
	int arr[][10]={{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
	int n=4,m=4;
	print(arr,n,m);
}
