#include<iostream>
using namespace std;

int search(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int main(){
    int arr[]= {10, 20, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    cout<<x<<" is at "<<search(arr, n, x)+1<<"th position.";
    return 0;
}