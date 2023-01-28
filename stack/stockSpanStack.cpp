#include<iostream>
#include<stack>
using namespace std;
void stockSpan(int *arr,int n){
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(st.empty() == false && arr[st.top()] < arr[i]){
            st.pop();
        }
        int span = (st.empty()) ? (i+1) : (i - st.top());
        cout<<span<<" ";
        st.push(i);
    }
}
int main(){
    int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    stockSpan(arr, n);
    return 0;
}