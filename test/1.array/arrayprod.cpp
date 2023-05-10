#include<iostream>
#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    vector<int> left(n,1);
    vector<int> right(n,1);
   
	
    for(int i=1;i<n;i++){
    	left[i]=arr[i-1]*left[i-1];
    	
	}
	for(int i=n-2;i>=0;i--){
		right[i]=arr[i+1]*right[i+1];
	
	}
	for(int i=0;i<n;i++){
		if(i==0){
			output[i]=right[i];
			
		}
		else if(i==n-1){
			output[i]=left[i];
		}
		else{
			output[i]=left[i]*right[i];
		}
	}
    
    //update the output array and return
    //complete the code
    
    
    
    return output;
}

int main(){
	vector<int> arr={1,2,3,4,5};
	vector<int> op;
	cout<<endl;
	op=productArray(arr);
	for(int i=0;i<op.size();i++){
		cout<<op[i]<<" ";
	}
}
