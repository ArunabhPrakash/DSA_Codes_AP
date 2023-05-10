#include<iostream>
using namespace std;


string compressString(string str){

	int n = str.length();

	string output;

	for(int i=0;i<n; i++){

		int count = 1;

		while(i< n-1 and str[i+1] == str[i]){//redundant, could have done in o(n), just check if same as next then count++,when dif just concat
			count++;
			i++;
		}
		output += str[i];
		output += to_string(count);

	}
	if(output.length() > str.length()){
		return str;
	}
	return output;

}


int main(){

    string s1 = "aaabbccddee";
    cout << compressString(s1)<<endl;

    string s2 = "abcd";
    cout<< compressString(s2)<<endl;


    return 0;
}
