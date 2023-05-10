#include<iostream>
using namespace std;
int difference_calc(int n,int a[]){
	int val=a[0];
	int index=1;
	int consec=1;
	int instance1=0;
	int instance2=0;
	for(int i=0;i<n;i++){
		if(i==n-1){
				if(consec==val){
				instance1++;
				}
				if(index<=val && consec>=val){
					instance2++;
				}
		}
		else{
				if(a[i]==a[i+1]){
				consec++;
			}
			else{
				if(consec==val){
					instance1++;
					
				}
				if(index<=val && consec>=val){
					instance2++;
				}
				consec=1;
				val=a[i+1];
				index=i+1;
			}
		}
		
	}
	return instance1-instance2;
}
int main(){
	int arr[]={1,2,2,2,2,3,3,3,1,1,2,2};
	int n=sizeof(arr)/sizeof(int);
	cout<<difference_calc(n,arr);
}
