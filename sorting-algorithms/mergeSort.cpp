#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];
    
    for(int i = 0; i < n1; i++)
        left[i] = arr[l+i];
    for(int j = 0; j < n2; j++)
        right[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i<n1) arr[k++] = left[i++];
    while(j<n2) arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r){
    //check array have atleast two element
    if(r > l){
        int m = l + (r-l)/2;
        mergeSort(arr, l , m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m , r);
    }
}
int main(){
    
    int arr[] = {2, 5, 10, 20, 25, 1, 3, 15, 20, 30, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]); 
    mergeSort(arr, 0, n-1);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}