#include<iostream>
using namespace std;


void countingSort(int arr[], int n, int exp){
    // declear count array of size max range to store no of occurance
    //we have to deal with digits so range is 0-9
    int count[10];

    // initilize count array with all element as 0
    for(int i = 0; i < 10; i++)
        count[i] = 0;

    //increment count of every element
    //pass array element as index of count
    //arr[i]/exp)%10 gives if exp = 1, last digit
    //                     if exp = 10, second last digit..

    for(int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    //do commulative sum
    //store no of element smaller or equals
    //it's give correct position of element in sorted array

    for(int i = 1; i < 10; i++)
        count[i] = count[i-1] + count[i];

    //create an temp array and store all element at its correct position
    int output[n];
    for(int i = n-1; i >= 0; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    //copy array to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
    
}

//radix sort
//it's sort element by sorting their respective digits

void radixSort(int arr[], int n){
    //find the greater element to have maximun no of digits
    int mx = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > mx)
            mx = arr[i];
    }
    //it's uses counting sort as subroutine
    //call counting sort for max no of digits

    for(int exp = 1; mx/exp > 0; exp *= 10){
        countingSort(arr, n, exp);
        }
}



int main(){
    int arr[] = {319, 212, 6, 8, 100, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}