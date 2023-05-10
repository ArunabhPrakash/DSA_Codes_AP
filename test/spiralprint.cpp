#include<iostream>
using namespace std;
void print(int arr[][10],int row,int col){
	int startrow=0;
	int endrow=row-1;
	int startcol=0;
	int endcol=col-1;
	while(startcol<endcol and startrow<endrow){
		for(int col=startcol;col<=endcol;col++){
			cout<<arr[startrow][col]<<" ";
		}
		
		for(int row=startrow+1;row<=endrow;row++){
			cout<<arr[row][endcol]<<" ";
		}
		
		for(int col=endcol-1;col>=startcol;col--){
			cout<<arr[endrow][col]<<" ";
		}
	
		for(int row=endrow-1;row>=startrow+1;row--){
			cout<<arr[row][startcol]<<" ";
		}
		startrow++;
		startcol++;
		endrow--;
		endcol--;
		
	}
}
int main(){
	int arr[][10]={{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
	int r=4,c=4;
	print(arr,r,c);
}
