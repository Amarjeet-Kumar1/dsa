#include<iostream>
#include<unordered_set>
using namespace std;

// find pair with given sun is present in an unsorted array
// IP {3, 2, 8, 15, -8}
// sum = 17
// OP Yes

// naive solution
// time O(n2), space O(1)
// bool isPair(int arr[], int n, int sum){
//     for(int i = 0; i < n; i++)
//         for(int j = i+1; j < n; j++)
//             if((arr[i] + arr[j]) == sum)
//                 return true;

//     return false;
// }

//efficient solution
//using unordered_set
//time O(n) space O(n)

bool isPair(int arr[], int n, int sum){
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        if(s.find(sum-arr[i]) != s.end())
            return true;
        s.insert(arr[i]);
    }
    return false;
    
}
int main(){
    int arr[] = {3, 2, 8, 15, -8};
    // int arr[] = {5, 8, -3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 17;
    if(isPair(arr, n, sum))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}