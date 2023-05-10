#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int> &array,int s,int e){
	int i=s;
	int m=(s+e)/2;
	int j=m+1;
	int cnt=0;
	vector<int> temp;
	while(i<=m and j<=e){
		if(array[i]<array[j]){
			temp.push_back(array[i]);//no need to maintain k and easy insertion using vector
			i++;
		}
		else{
			cnt+=(m-i+1);
			temp.push_back(array[j]);
			j++;
		}
	}
	while(i<=m){
		temp.push_back(array[i++]);
		
	}
	while(j<=e){
		temp.push_back(array[j++]);
	}
	int k=0;
	for(int idx = s;idx<=e;idx++){
		
		array[idx] = temp[k++];
	}
	return cnt;
}

int inversion_count(vector<int> &array,int s,int e){
	if(s>=e){
		return 0;
	}
	
	int mid=(s+e)/2;
	int C1=inversion_count(array,s,mid);
	int C2=inversion_count(array,mid+1,e);
	int CI=merge(array,s,e);
	return C1+C2+CI;
}

int main(){
	vector<int> array{0,5,2,3,1};
	int s=0;
	int e=array.size()-1;
	cout<<inversion_count(array,s,e);

}
