#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool isNumeric(char c){
    return (c >= '0' && c <= '9');
}
int doOperation(char oper, int op1, int op2){
    switch(oper){
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '^': return pow(op1,op2);
        default: return INT_MIN;
    }
}

int evalPostfix(string str){
    
    stack<int> st;
    for(int i = 0; i < str.length(); i++){
        
        if(str[i] == ' ' || str[i] == ',') continue; 
        else if(isOperator(str[i])){
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int res = doOperation(str[i], op1, op2);
            st.push(res);
        } else if(isNumeric(str[i])) {
            int num =0;
            while(isNumeric(str[i])){
                num = (num*10) + (str[i]-'0');
                i++;
            }
            i--;
            st.push(num);
        }
    }
    return st.top();

}

int main(){
    string str =  "5 2+3*";
    cout<<evalPostfix(str);
    
    return 0;
}