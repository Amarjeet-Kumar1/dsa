#include<iostream>
#include<unordered_set>
using namespace std;

//count distict element in an array
// IP {15, 12, 13, 12, 13, 13, 18}
// OP 4

// IP {10,10, 10}
// OP 1

//unordered_set stores only unique key and ignore duplicate element
// time for one insert is O(1)
//time complexity of this program O(n) and O(n) auxilary space
int countDistinct(int arr[], int n){
    unordered_set<int> set;
    for(int i = 0; i < n; i++)
        set.insert(arr[i]);

    return set.size();
}

int main(){
    int arr[] = {15, 12, 13, 12, 13, 13, 18};
    // int arr[]= {10, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<countDistinct(arr, n);
    return 0;
}