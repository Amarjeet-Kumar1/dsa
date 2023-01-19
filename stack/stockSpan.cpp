#include<iostream>
using namespace std;
void stockSpan(int *arr, int n){
    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = i-1; j >= 0; j--){
            if(arr[j] <= arr[i]){
                count++;
            }
            else {
                break;
            }
        }
        cout<<count<<" ";
    }
}
int main(){
    int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    stockSpan(arr, n);
    return 0;
}