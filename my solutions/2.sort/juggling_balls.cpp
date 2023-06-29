#include<iostream>
#include<vector>
using namespace std;


vector<int> sortBalls(vector<int> balls){
	int i=-1;
	int j=0;
	int k=balls.size();
	while(j<k){
		if(balls[j]==0){
			i++;
			swap(balls[i],balls[j]);
			j++;
		}
		else if(balls[j]==2){
			k--;
			swap(balls[j],balls[k]);
		}
		else{
			j++;
		}
	}
    return balls;
}

