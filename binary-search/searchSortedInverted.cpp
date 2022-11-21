#include<iostream>
using namespace std;

int inSearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    
    while (low <= high)
    {

        int mid = (low + high)/2;
        if(arr[mid] == x) return mid;
        if(arr[low] < arr[mid]){
            if(x >= arr[low] && x < arr[mid])
                high = mid - 1;
            else low = mid + 1;
        }
        else {
            if(x<=arr[high] && x > arr[mid])
                low = mid + 1;
            else high = mid -1;
        }
    }
    return -1;
    
}

int main(){
    int arr[] = { 40, 45, 50, 55, 30, 35};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 30;
    cout<<inSearch(arr, n, x);
    return 0;
}