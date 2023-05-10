#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> printPascal(int n)
{
    vector<vector<int>> result;
    result[0][0]=1;
    for(int i=1;i<n;i++){
    	for(int j=0;j<=i;j++){
    		if(j-1==-1){
    			result[i][j]=result[i-1][j];
    			cout<<result[i][j];
			}
			else if(j==i){
				result[i][j]=result[i-1][j-1];
				cout<<result[i][j];
			}
			else{
				result[i][j]=result[i-1][j-1]+result[i-1][j];
				cout<<result[i][j];
			}
			
    		
		}
	}
    
    
}

int main(){
	int n=5;
	
	vector<vector<int>> result;
	result=printPascal(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}
