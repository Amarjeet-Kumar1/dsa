#include<iostream>
#include<unordered_map>
using namespace std;
//longest subarray with given sum
//IP {5, 8, -4, -4, 9, -2, 2}
//       ---------     ------
//sum = 0
//Op 3


//naive
//O(n2) time

// int maxLen(int arr[], int n, int sum){
//     int res = 0;
//     for(int i = 0; i < n; i++){
//         int curr_sum = 0;
//         for(int j = i; j < n; j++){
//             curr_sum += arr[j];
//             if(curr_sum == sum)
//                 res = max(res, j-i+1);
//         }
//     }
//     return res;
// }

//efficient solution
//o(n) time with O(n) auxilary space

int maxLen(int arr[],int n, int sum){
    unordered_map<int, int> mp;
    int pre_sum = 0, res = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(pre_sum == sum) res = i+1;

        //store pre_sum and its first occurance index
        if(mp.find(pre_sum) == mp.end())
            mp.insert({pre_sum, i});
        if(mp.find(pre_sum-sum) != mp.end())
            res = max(res, i-mp[pre_sum-sum]);
    }
    return res;
}

int main(){
    int arr[] = {5, 8, -4, -4, 9, -2, 2};
    int sum = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxLen(arr, n, sum);
    return 0;
}