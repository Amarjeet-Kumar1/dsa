#include<iostream>
using namespace std;
void lRotateOne(int arr[], int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
int main(){
    int arr[] = {10, 20, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    lRotateOne(arr, n);
    cout<<"Rotated Array is: ";
    for(int i= 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}