#include<iostream>
#include<stack>
using namespace std;
void prevGreater(int *arr, int n){
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(st.empty() == false && st.top() < arr[i]){
            st.pop();
        }
        if(st.empty()){
            cout<<"-1"<<" ";
        } else {
            cout<<st.top()<<" ";
        }
        st.push(arr[i]);
    }


}
int main(){
    // int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    int arr[] = {8, 10, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    prevGreater(arr, n);
    return 0;
}