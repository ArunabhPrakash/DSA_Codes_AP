class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int cornerMax=INT_MIN;
        int centerMax=INT_MIN;
        int start =-1;
        int end = -1;
        int count=0;
        int finalV;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0){
                count++;
            }
            else{
                end=i;
                if(start==-1 and end!=-1){
                    cornerMax=max(count,cornerMax);
                    count=0;
                }
                else{
                    if(count%2==0){
                        count=(count/2);
                        centerMax=max(count,centerMax);
                        count=0;
                    }
                    else{
                        count=(count/2)+1;
                        centerMax=max(count,centerMax);
                        count=0;
                    }
                }
                
                    start=i;
                    end=-1;
            }
            
        }
        if(start!=-1 and end==-1){
                    cornerMax=max(cornerMax,count);
        }
        finalV = max(cornerMax,centerMax);
    return finalV;
    }
};
