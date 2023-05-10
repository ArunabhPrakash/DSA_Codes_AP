#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
string simplifypath(string path){
	istringstream iss(path);
	vector<string> tokens;
	
	string token;
	while(getline(iss,token,'/')){//converted to token
		if(token=="." or token==""){
			continue;
		}
		tokens.push_back(token);
	}

	vector<string> stack;//used vector as stack for better mobility
	if(path[0]=='/'){
		stack.push_back("");//for abs path
	}
	for(string token: tokens){
		if(token==".."){
			if(stack.size()==0 or stack[stack.size()-1]==".."){
				stack.push_back("..");
			}
			else if(stack[stack.size()-1]!=""){
				stack.pop_back();
			}
		}
		else{
			stack.push_back(token);
		}
	}
	if(stack.size()==1 and stack[0]==""){
		return "/";
	}
	ostringstream oss;
	for(auto token:stack){
		oss << token<<"/";
	}
	return oss.str();
}
int main(){
	string path = "/../x/y/../z/././w/a///../../c/./";
	cout<<simplifypath(path);
}
