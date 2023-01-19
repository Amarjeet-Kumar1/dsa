#include<iostream>
using namespace std;
class TwoStack{
    private:
        int *arr, cap, top1, top2;
    public:
        TwoStack(int n){
            cap = n;
            top1 = -1;
            top2 = cap;
            arr = new int[n];
        }
        void push1(int x){
            if(top1 < top2 - 1){
                top1++;
                arr[top1] = x;
            }
        }
        void push2(int x){
            if(top1 < top2 - 1){
                top2--;
                arr[top2] = x;
            }
        }
        int pop1(){
            if(top1 >= 0){
                int x = arr[top1];
                top1--;
                return x;
            } else {
                cout<<"stack 1 underflow";
                exit(1);
            }
        }
        int pop2(){
            if(top2 < cap){
                int x = arr[top2];
                top2++;
                return x;
            } else {
                cout<<"stack 2 underflow";
                exit(1);
            }

        }
        int topy1(){
            return arr[top1];
        }
        int topy2(){
            return arr[top2];
        }

};
int main(){
     TwoStack stack(5);
     stack.push1(5);
     stack.push1(6);
     cout<<stack.topy1();
     stack.pop1();
     cout<<stack.topy1();
     stack.push2(8);
     cout<<stack.topy2();

    return 0;
}