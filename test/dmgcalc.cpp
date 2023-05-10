#include<iostream>
using namespace std;
void dmgcalc(int arr[],int dp[],int i,int armor,int Td,int dpi){
	if(i<0){
		
		dp[dpi]=Td;
		
	}
	else{
		if(armor!=0){
		int block=min(arr[i],armor);
		int dmg=arr[i]-block;
		dpi=i;
		Td+=dmg;
		
		armor=0;
		dmgcalc(arr,dp,i-1,armor,Td,dpi);
		}
		Td+=arr[i];
		dmgcalc(arr,dp,i-1,armor,Td,dpi);
		
	}
	
}
int main(){
	int power[]={1,3,6,4};
	int n=sizeof(power)/sizeof(int);
	int armor=5;
	int i=n-1;
	int Td=0;
	int dp[]={0,0,0,0};
	int dpi=-1;
	dmgcalc(power,dp,i,armor,Td,dpi);
	for(int i=0;i<n;i++){
		cout<<dp[i];
	}
}
