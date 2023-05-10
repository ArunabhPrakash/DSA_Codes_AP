#include<iostream>
#include<stack>
using namespace std;

// ??? Dont know what to do .
removeDuplicateParenthesis(char *a,int n){
    stack<char> s;
    char b[100];
    int i=0;
    int j=0;
    while(a[i]!='\0'){
        if(a[i]=='('){
            b[j++] = '('
            s.push('(');
        }
        else if(a[i]==')'){
        while(s.top()!='('){
                count++;
                s.pop();
            }

        }


    i++;
    }

}
bool checkRedundant(string str){
	stack<char> s;
	for(char ch: str){
		if(ch!=')'){
			s.push(ch);
		}
		else{
			bool operator_found = false;
			while(!s.empty() and s.top()!='('){
				char top = s.top();
				if(top =='+' or top=='-' or top=='*' or top=='/'){
					operator_found=true;
				}
				s.pop();
			}
			s.pop();//pop opening bracket
			if(operator_found==false){
				return true;
			}
		}
	}
	return false;
}

int main(){
char a[] ="((a+b)+ ((c-d)))";
int  n = sizeof(a)/sizeof(char);
removeDuplicateParenthesis(a,n);

return 0;
}
