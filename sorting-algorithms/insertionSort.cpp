#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
    for(int i = 1; i< n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>= 0 && arr[j]>key ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {2, 5, 1, 15, 4};
    int n =  sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}