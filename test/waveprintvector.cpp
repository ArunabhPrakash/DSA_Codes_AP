#include<iostream>
#include<vector>
using namespace std;
 
 vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{	vector<int> result;
   for(int j=n-1;j>=0;j--){
		if(j%2==1){
			for(int i=0;i<m;i++){
				cout<<arr[i][j]<<" ";
				result.push_back(arr[i][j]);
			}	
		}
		else{
			
			for(int i=m-1;i>=0;i--){
				cout<<arr[i][j]<<" ";
				result.push_back(arr[i][j]);
			}	
		}
	}
	return result;
}

int main(){
	vector<vector<int>> vect
    {
        {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
    };
    int r=4,c=4;
    WavePrint(r,c,vect);
}
