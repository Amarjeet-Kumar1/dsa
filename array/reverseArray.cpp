#include<iostream>
using namespace std;
void reverseArray(int arr[], int n){
    int low = 0, high = n-1;
    while(low<high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high]= temp;
        low++;
        high--;

    }
}
int main(){
    int arr[] = {10, 20, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, n);
    cout<<"reversed array is: ";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}