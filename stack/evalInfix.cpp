#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

bool isOpretor(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
bool isNumeric(char c){
    return (c >= '0' && c <= '9');
}
int doOperation(char c, int op1, int op2){
    switch(c){
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 + op2);
        case '^': return pow(op1,op2);
        default: return INT_MIN;
    }

}

int evalInfix(string str){
    stack<int> st;
    for(int i = str.length()-1; i >= 0; i--){
        char c = str[i];
        if(str[i] == ' ' || str[i] == ',') continue;
        else if(isOpretor(str[i])){
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            st.push(doOperation(str[i], op1, op2));

        } else if(isNumeric(str[i])){
            int num = 0;
            while(isNumeric(str[i])){
                num = (num*10) + (str[i] - '0');
                i--;

            }
            i++;
            st.push(num);
        }
    }
    return st.top();
}

int main(){
    string str= "+5*4 2";
    cout<<evalInfix(str);
    return 0;
}