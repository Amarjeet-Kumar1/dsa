#include<iostream>
#include<stack>
using namespace std;

bool isMatching(char a, char b){
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}

bool isBalanced(string str){
    stack<int> st;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            st.push(str[i]);
        } else {
            if(st.empty() == true){
                return false;
            } else if(isMatching(st.top(), str[i] ) == false){
                return false;
            } else {
                st.pop();
            }
        }
    }
   
    
    return (st.empty() == true);
}

int main(){
    string str = "((()))";
    cout<<isBalanced(str);

    return 0;
}