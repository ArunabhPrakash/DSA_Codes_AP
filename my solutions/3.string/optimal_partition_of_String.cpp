#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
  
    int partitionString(string s) {
        unordered_set<char> temp;
        int count =1;
        for(int i=0;s[i]!='\0';i++){
            if(temp.find(s[i])==temp.end()){
                temp.insert(s[i]);
                cout<<"\ninserted"<<s[i];
            }
            else{
                count++;
                temp.clear();
                cout<<"\nsize="<<temp.size()<<" and inserted"<<s[i];
                temp.insert(s[i]);
            }
        }
    return count;
    }
    
int main(){
	string a = "abacaba";
	cout<<partitionString(a);
}
