#include<iostream>
#include<algorithm>
using namespace std;

//lomuto partition
//its assume last element as pivot

int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i = l-1;
    for(int j = l; j < h; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    //for pivot, last element
    swap(arr[i+1], arr[h]);
    //return index of pivot
    return (i + 1);
}

//quick sort
void quickSort(int arr[], int l, int h){

    //atleast two element in array
    
    if(l < h){
        int p = partition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

int main(){
    int arr[] = {8, 4, 7, 9, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}