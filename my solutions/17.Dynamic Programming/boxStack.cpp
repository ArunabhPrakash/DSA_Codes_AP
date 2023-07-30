#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Box{//working in general, dont know sort on which basis
	public:
		int w;
		int d;
		int h;
		Box(int a,int b,int c){
			w=a;
			d=b;
			h=c;
		}
};
int boxStack(vector<Box> &boxes,int n){
	if(n<0){
		return 0;
	}
	else{
		int finCnt = 0;
		for(int i=n-1;i>=0;i--){
			
			if(boxes[n].w>boxes[i].w and boxes[n].d>boxes[i].d and boxes[n].h>boxes[i].h){
				int count=boxes[n].h + boxStack(boxes,i);
				finCnt = max(count,finCnt);
				cout<<"\nentered if";
			}
			cout<<"\n@calling i="<<i<<" fincnt= "<<finCnt;
		}
		return finCnt;
	}
}
int boxMain(vector<Box> &boxes,int n,int maxV){
	if(n<0){
		return maxV;
	}
	else{
		int cnt = boxStack(boxes,n);
		cout<<"\nboxMain :n="<<n<<" count= "<<cnt<<" maxV="<<maxV;
		maxV=max(maxV,cnt);
		return boxMain(boxes,n-1,maxV);
	}
}
bool compare(Box &a,Box &b){
	return a.d<b.d and a.h<b.h and a.w<b.w;
}
int main(){
	Box ob1 = Box(2,1,2);
	Box ob2 = Box(3,2,3);
	Box ob3 = Box(2,2,8);
	Box ob4 = Box(2,3,4);
	Box ob5 = Box(2,2,1);
	Box ob6 = Box(4,4,5);
	vector<Box> arr = {ob1,ob2,ob3,ob4,ob5,ob6};
	sort(arr.begin(),arr.end(),compare);
	for(auto i:arr){
		cout<<"\n"<<i.d<<" "<<i.h<<" "<<i.w;
	}
	cout<<"\n";
	
	cout<<boxMain(arr,arr.size()-1,INT_MIN);	
}
