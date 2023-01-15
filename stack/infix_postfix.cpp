#include<iostream>
#include<stack>
using namespace std;

// return precedence 
int prec(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else return -1;
}

//infix to postfix

void postfix(string str){
    stack<char> st;
    string result;
    for(int i = 0; i < str.length(); i++){
        char x = str[i];
        
       
        //if operand, then print
        if((x >= 'a' && x <= 'z') || (x >='A' && x <= 'Z') || (x >= '0' && x <= '9')) 
            result +=x; 
        else if(x == '(')
                st.push(x);
        else if(x == ')'){
                while(st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
        }
        else {
            while(!st.empty() && prec(x) <= prec(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(x);

        }

    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout<< result << endl;
}

int main(){
//    string str = "(x+y)*z";
   string str = "a+b/c*d*e";

   postfix(str);


    return 0;
}