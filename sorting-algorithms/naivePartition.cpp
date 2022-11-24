#include<iostream>
using namespace std;

void partition(int arr[], int l, int h, int p){
    int temp[h-l+1], index=0;
    for(int i = l; i <= h; i++)
        if(arr[i]<=arr[p])
            temp[index++] = arr[i];

    for(int i = l; i <= h; i++)
        if(arr[i] > arr[p])
            temp[index++] = arr[i];

    for(int i = l; i <= h; i++)
        arr[i] = temp[i-l];
}

int main(){
    int arr[] = {3, 8, 7, 6, 12, 10, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    partition(arr, 0, n-1, 6);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}