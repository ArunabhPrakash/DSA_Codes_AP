#include<iostream>
using namespace std;

void waveprint(int arr[][10],int row,int col){
	for(int j=col-1;j>=0;j--){
		if(j%2==1){
			for(int i=0;i<row;i++){
				cout<<arr[i][j]<<" ";
			}	
		}
		else{
			
			for(int i=row-1;i>=0;i--){
				cout<<arr[i][j]<<" ";
			}	
		}
	}
}
int main(){
	int arr[][10]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int r=4,c=4;
	waveprint(arr,r,c);
}

