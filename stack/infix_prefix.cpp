#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int precedence(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void infix_prefix(string str){
    stack<char> st;
    string prefix;
    for(int i = str.length() -1; i >= 0; i--){
        char c = str[i];
        
        if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            prefix.push_back(c);
        } else if(c == ')'){
            st.push(c);
        } else if(c == '('){
            while(st.top() != ')'){
                prefix.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && (precedence(c) < precedence(st.top()))){
                prefix.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        prefix.push_back(st.top());
        st.pop();
    }
    reverse(prefix.begin(), prefix.end());
    cout<<prefix;
}

int main(){

    string str = "(a+b)*c";
    infix_prefix(str);


    return 0;
}