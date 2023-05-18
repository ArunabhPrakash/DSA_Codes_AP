#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
     int row = matrix.size();
     int n=row;
     int start =0;
     int end=row-1;
     int mid = row/2;
     cout<<"\nmid"<<mid;
     vector<int> temp (n);
     vector<int> temp2 (n);
     while(mid>0){
     	cout<<"\n for n="<<n<<endl;
         for(int i=0;i<row;i++){
             temp[i] = matrix[i][end];
             cout<<"temp"<<i<<" :"<<temp[i];
             matrix[i][end] = matrix[start][i];
         }
         cout<<endl;
         for(int i=0;i<row;i++){
             
			 temp2[i]=matrix[end][row-i-1];
			 cout<<"temp2"<<i<<" :"<<temp2[i];
             matrix[end][row-i-1]=temp[i];
         }
         temp2[start]=temp[end];
         cout<<endl;
         for(int i=0;i<row;i++){
             temp[i]=matrix[row-i-1][start];
             cout<<"temp"<<i<<" :"<<temp[i];
             matrix[row-i-1][start]=temp2[i];
         }
         temp[start] = temp2[end];
         for(int i=0;i<row;i++){
             matrix[start][i]=temp[i];
         }
         mid--;
         start++;
         end--;
     }
      
}

int main(){
	//vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr.size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	rotate(arr);
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr.size();j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

