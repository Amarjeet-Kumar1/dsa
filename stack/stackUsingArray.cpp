#include<iostream>
using namespace std;
class Stack{
    private:
        int *arr;
        int cap;
        int top;
    public:
        
        Stack(int d){
            arr = new int[d];
            cap = d;
            top = -1;
        }   
        void push(int x){
            if(top == cap-1){
                cout<<"stack overflow";
                return;
            }
            top++;
            arr[top] = x;
        }
        int pop(){
            if(top == -1){
                cout<<"stack underflow";
                return INT_MIN;
            }
            int res = arr[top];
            top--;
            return res;
        }
        int topy(){
            return arr[top];
        }

};
int main(){
    Stack st(5);
    st.push(5);
    st.push(6);
    cout<<st.topy()<<endl;
    st.pop();
    cout<<st.topy();

    return 0;
}