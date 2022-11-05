#include<iostream>
using namespace std;
int insertEle(int arr[], int n, int x, int pos, int cap){
    if(n == cap)
        return n;
    int idx = pos-1;
    for(int i=n-1;i>=idx;i--){
        arr[i+1]= arr[i];
    }
    arr[idx] = x;
    return n+1;
    }

int main(){
    int x = 15, pos = 3, cap = 5;
    int arr[cap] = {10, 20, 5, 6};
    int n = 4;
    int insert = insertEle(arr, n, x, pos, cap);
    if(insert == n+1)
    {
    cout<<x<<" is inserted at position: "<<pos<<endl;
    cout<<"new array is: ";
    for(int i =0; i<n+1;i++){
        cout<<arr[i]<<" ";
    }
    }
    else if(insert == n){
        cout<<"Array is full.";
    }
    return 0;
}