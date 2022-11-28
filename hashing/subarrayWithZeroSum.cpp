#include<iostream>
#include<unordered_set>
using namespace std;

//if there is a subarray of given array with zero sum present
// IP {1, 4, 13, -3, -10, 5}
//           -----------
// OP yes

//naive solution
//time O(n2) space O(1)

// bool isSubarrayWithZeroSum(int arr[], int n){
//     for(int i = 0; i < n; i++){
//         int curr_sum = arr[i];
//         for(int j = i+1; j < n; j++){
//             curr_sum += arr[j];
//             if(curr_sum == 0)
//                 return true;
//         }
//     }
//     return false;
// }

//efficient solution
//using unsorted_set
//time O(n), auxilary space o(n)
//first find cummulative sum array(prefix sum array)
//if there is a prefix sum that repeats
//or prefix sum becomes zero than we hava pair with sum zero

bool isSubarrayWithZeroSum(int arr[], int n){
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n ; i++){
        pre_sum += arr[i];
        if(s.find(pre_sum) != s.end())
            return true;
        if(pre_sum == 0)
            return true;
        s.insert(pre_sum);
    }
    return false;
}

int main(){
    int arr[] = { 1, 4, 13, -3, -10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isSubarrayWithZeroSum(arr, n))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}