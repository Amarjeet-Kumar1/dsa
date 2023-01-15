#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> stack;
    stack.push(10);
    stack.push(14);
    stack.push(5);
    cout<<stack.size()<<endl;
    cout<<stack.top();
    stack.pop();
    cout<<stack.top();
    return 0;
}