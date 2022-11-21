#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int x){
    int low = 0, high = n-1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            high = mid-1;
        else low = mid+1;
    }
    return -1;
    
}
int main(){
    int arr[] = { 0, 5, 10, 15, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    cout<< binarySearch(arr, n, x);
    return 0;
}