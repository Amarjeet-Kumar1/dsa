#include<iostream>
#include<algorithm>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i< n-1; i++){
        int min_ind = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min_ind])
                min_ind = j;
        }
        swap(arr[min_ind], arr[i]);
    }
}
int main(){
    int arr[] = {2, 5, 1, 15, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}