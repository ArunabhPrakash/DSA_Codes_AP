#include<iostream>
using namespace std;

pair<int,int> staircaseSearch(int arr[][4],int row,int col,int key){
	pair<int,int> coords;
	coords.first=-1;
	coords.second=-1;
	int i=0;
	int j=col-1;
	while(i<row and j>=0){
		if(key==arr[i][j]){
			coords.first=i;
			coords.second=j;
			return coords;
		}
		else if(key>arr[i][j]){
			i++;
		}
		else{
			j--;
		}
	}
	return coords;	
}

int main(){
	int arr[][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
	int n=4,m=4;
	pair<int,int> coords = staircaseSearch(arr,n,m,50);
	cout<<coords.first<<" "<<coords.second<<endl;
	return 0;
}
