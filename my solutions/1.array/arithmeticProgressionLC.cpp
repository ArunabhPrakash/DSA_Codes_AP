class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

     unordered_set<double> mappy;
     double minVal=INT_MAX;
     double minD = INT_MAX;
     for(int i=0;i<arr.size();i++){
         mappy.insert(arr[i]);
         double t = arr[i];
         double currD=abs(double(t-minVal));
         if(minVal!=t){
            minD = min(minD,currD);
         }
         minVal = min(minVal,t);
         
         
     }
     vector<int> copyVector(arr.size(), minVal);
     if(arr == copyVector){
         return true;
     }
    double inst = minVal;
    for(int i=2;i<=arr.size();i++){
        inst = inst+minD;
        if(mappy.find(inst)==mappy.end()){
            return false;
        }
    }
    return true;
    }
};
