#include<iostream>
using namespace std;
void lRotatebyD(int arr[], int n, int d){
    int temp[d];
    for(int i = 0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int i = d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i = 0; i<d; i++){
        arr[n-d+i] = temp[i];
    }
}
int main(){
    int arr[] = {10, 20, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d;
    cout<<"Value of d: ";
    cin>>d;
    lRotatebyD(arr, n, d);
    cout<<"Rotated Array is: ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}