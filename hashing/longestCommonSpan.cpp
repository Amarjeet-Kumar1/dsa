#include<iostream>
#include<unordered_map>
using namespace std;

//find longest common subarray with same sum in two binary arrays
//staring and ending index should be same in both, sum should also be same
//arrangement can be different
//IP a[] = {0, 1, 0, 0, 0, 0}
//             ----------- 
//  b[] = {1, 0, 1, 0, 0, 1}
//            -----------  
//OP 4


//naive solution
//O(n2)
//consider both array are of same size
// int commonSpan(int a[], int b[], int m){
//     int res = 0;
//     for(int i = 0; i < m; i++){
//         int curr_sum1 = a[i];
//         int curr_sum2 = b[i];
//         for(int j = i+1; j < m; j++){
//             curr_sum1 += a[j];
//             curr_sum2 += b[j];
//             if(curr_sum1 == curr_sum2)
//                 res = max(res, j-i+1);
//         }
//     }
//     return res;
// }

//efficiet solution
//using unordered_map
//create a new array as different of element of both array
//now we just need to find lenth of longest subarray with sum zero
//to find desired solution

int commonSpan(int a[], int b[], int m){
    int arr[m];
    for(int i = 0; i < m; i++){
        arr[i] = (a[i] - b[i]);
    }
    unordered_map<int, int> mp;
    int pre_sum = 0, res = 0;
    for(int i = 0; i< m; i++){
        pre_sum += arr[i];
        if(pre_sum == 0) res = i +1;
        if(mp.find(pre_sum) == mp.end())
            mp.insert({pre_sum, i});
        if(mp.find(pre_sum) != mp.end())
            res = max(res, i-mp[pre_sum]);
    }
    return res;

}

int main(){
    int a[] = {0, 1, 0, 0, 0, 0};
    int b[] = {1, 0, 1, 0, 0, 1};
    // int a[] = {0, 1, 0, 1, 1, 1, 1};
    // int b[] = {1, 1, 1, 1, 1, 0, 1};
    int m = sizeof(a)/sizeof(a[0]);
    cout<<commonSpan(a, b, m);
    return 0;
}