#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool match(string brace){
    stack<char> st;
    auto len = brace.length();
    
    for(auto i=0;i<len;i++){

        if(brace[i] == '{' || brace[i] == '[' || brace[i] == '(') st.push(brace[i]);

        else {
            if(st.empty()){
                return false;
            }
            char a = st.top();
            st.pop();
            if(brace[i] == '}' && a != '{') return false;
            else if(brace[i] == ']' && a != '[') return false;
            else if(brace[i] == ')' && a != '(') return false;   
            else continue; 
        }
    }
    return st.empty(); 
}

int main(){
    string b = "{()}[]";
    bool m = match(b);
    cout<<m;
}
