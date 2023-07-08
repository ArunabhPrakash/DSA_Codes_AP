#include<iostream>
#include<vector>
using namespace std;

    //     int ts=0;
    //     int sum=0;
    //     int target;
    //     int loc=-1;
    //     int sum1=0;
    //     int sum2=0;
    //     for(int i=0;i<nums.size();i++){
    //         ts+=nums[i];
    //     }
    //     target = ts/2;
    //     if(ts<0){
    //     for(int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //         if(sum<target){
    //             loc=i;
    //             break;
    //         }
    //     }
    //     }
    //     else{
    //     for(int i=0;i<nums.size();i++){
    //         sum+=nums[i];
    //         if(sum>target){
    //             loc=i;
    //             break;
    //         }
    //     }           
    //     }

    //     for(int i=0;i<loc;i++){
    //         sum1+=nums[i];
    //     }
    //     for(int i=loc+1;i<nums.size();i++){
    //         sum2+=nums[i];
    //     }
    //     if(sum1==sum2){
    //         return loc;
    //     }
    //     else{
    //         return -1;
    //     }
    // }
         int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    int loc=-1;
    vector<int> prefix_sum(n);
	prefix_sum[0]=nums[0];
    for(int i=1;i<n;i++){
        prefix_sum[i]=prefix_sum[i-1]+nums[i];
        cout<<prefix_sum[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        
        int side1;
        int side2;
        if(i==0 or i==n-1){
            if(i==0){
                int side1=0;
                int side2=prefix_sum[n-1]-prefix_sum[0];
                cout<<"\ni="<<i<<"side1="<<side1<<"side2="<<side2;
                if(side1==side2){
                         loc=i;
                        break;
                 }
            }
            else{
                int side1=prefix_sum[n-2];
                int side2=0;
                cout<<"\ni="<<i<<"side1="<<side1<<"side2="<<side2;
                if(side1==side2){
                         loc=i;
                        break;
                }
            }
        }
        else{

         side1=prefix_sum[i-1];
         side2=prefix_sum[n-1]-prefix_sum[i];
         cout<<"\ni="<<i<<"side1="<<side1<<"side2="<<side2;
        if(side1==side2){
            loc=i;
            break;
        }
        }

    }
    return loc;
}
int main(){
	vector<int> arr = {1,7,3,6,5,6};
	cout<<pivotIndex(arr);
}
