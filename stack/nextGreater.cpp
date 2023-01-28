#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nextGreater(int *arr, int n){
    stack<int> st;
    vector<int> v;
    for(int i = n-1; i >= 0; i--){
        while(st.empty() == false && st.top() < arr[i]){
            st.pop();
        }
        int next = (st.empty()) ? -1 : st.top();
        v.push_back(next);
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
int main(){
    int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = nextGreater(arr, n);
    for(auto  it : v){
        cout<<it<<" ";
    }
    return 0;
}