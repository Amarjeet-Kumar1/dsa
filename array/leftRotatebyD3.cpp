#include<iostream>
using namespace std;
void reverseArray(int arr[], int low, int high){
    while(low<high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void lRotate(int arr[], int n, int d){
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
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