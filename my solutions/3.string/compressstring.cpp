#include<iostream>
#include<string>
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
string compression2(string str){
	int count=1;
	string result;
	for(int i=1;str[i]!='\0';i++){
		if(str[i]==str[i-1]){
			count++;
		}
		else{
			result+=str[i-1];
			if(count>1){
				result+=to_string(count);
			}
			count=1;
		}
	}
	result+=str[str.size()-1];
	if(count>1){
		result+=to_string(count);
	}
	return result;
}

int main(){

    string s1 = "aaabbccddee";
    cout << compressString(s1)<<endl;
	cout<<compression2(s1)<<endl;
    string s2 = "abcd";
    cout<< compressString(s2)<<endl;
	cout<<compression2(s2)<<endl;

    return 0;
}
