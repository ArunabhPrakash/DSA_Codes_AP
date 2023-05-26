#include<iostream>
#include<vector>
using namespace std;//accepted on LC only last case TLE
//logic is simple, take minH as min health needed, and PH is positive health for buffer
//we start with both 0, if dungeon val negative then reduce buffer to 0 then add remaining to minH else keep increasing buffer, 
//this way we get initial min health, and not just total health req to complete
pair<int,int> checkRemaining(vector<vector<int>> &dungeon, int i,int j,int minH,int PH){
	
		int remaining=PH+dungeon[i][j];
		if(remaining>=0){
			PH=remaining;
		}
		else{
			minH=minH-remaining;
			PH=0;
		}
	
	return {minH,PH};
}
int calcMinHPHelper(vector<vector<int>> &dungeon,int i,int j,int m,int n,int minH,int PH){
	pair<int,int> p;
	if(i==m-1 and j==n-1){
		p=checkRemaining(dungeon,i,j,minH,PH);
		minH=p.first;
		PH=p.second;		
		return minH;
	}
	

	int pathRight=INT_MAX;
	int pathDown=INT_MAX;
	
	p=checkRemaining(dungeon,i,j,minH,PH);
	minH=p.first;
	PH=p.second;

	if(j+1<n){
		pathRight = calcMinHPHelper(dungeon,i,j+1,m,n,minH,PH);	
	}
	if(i+1<m){
		pathDown =calcMinHPHelper(dungeon,i+1,j,m,n,minH,PH);
	}
	int ans = min(pathRight,pathDown);
	return ans;
	
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //init 0,0 ij and minh=0,ph=0
        int m = dungeon.size();
        int n = dungeon[0].size();
        cout<<"\nm="<<m<<" n="<<n;
    return calcMinHPHelper(dungeon,0,0,m,n,0,0)+1;
}
int main(){
	vector<vector<int>> dungeon = {{3,-20,30},{-3,4,0}};//[[-2,-3,3],[-5,-10,1],[10,30,-5]] working both
	for(int i=0;i<dungeon.size();i++){
		for(int j=0;j<dungeon.size();j++){
			cout<<dungeon[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<calculateMinimumHP(dungeon);
}
