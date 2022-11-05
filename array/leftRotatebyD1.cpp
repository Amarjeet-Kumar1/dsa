#include<iostream>
using namespace std;
void lRotateOne(int arr[], int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
void lRotate(int arr[], int n, int d){
    for(int i = 0; i < d; i++){
        lRotateOne(arr, n);
    }
}
int main(){
    int arr[] = {10, 20, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d;
    cout<<"Value of d: ";
    cin>>d;
    lRotate(arr, n, d);
    cout<<"Rotated Array is: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}