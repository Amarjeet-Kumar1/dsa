#include<iostream>
using namespace std;
//countint sort algorithm fir given input range
//its count no of occurance of an element to sort 

void countingSort(int arr[], int n, int k){
    // declear count array of size k to store no of occurance
    int count[k];

    // initilize count array with all element as 0
    for(int i = 0; i < k; i++)
        count[i] = 0;

    //increment count of every element
    //pass array element as index of count

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    //do commulative sum
    //store no of element smaller or equals
    //it's give correct position of element in sorted array

    for(int i = 1; i < k; i++)
        count[i] = count[i-1] + count[i];

    //create an temp array and store all element at its correct position
    int output[n];
    for(int i = n-1; i >= 0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    //copy array to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
    
}

int main(){
    int arr[] = {1, 4, 4, 1, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr, n, 5);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}