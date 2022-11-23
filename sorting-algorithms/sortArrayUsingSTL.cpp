#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {2, 5, 1, 15, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<< "Sorting array in accencing order"<<endl;
    sort(arr, arr+n);
    for(int x: arr)
        cout<<x<<" ";
    
    cout<<"\nSorting array in decending order"<<endl;
    sort(arr, arr+n, greater<int>());
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}