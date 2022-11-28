#include<iostream>
#include<unordered_map>
using namespace std;
// find length of longest subarray with no of zero's and one's in binary array
//IP {1, 0, 1, 1, 1, 0, 0}
//      ------------------
//Op 6


//naive 
//O(n2)
// int longSub(bool arr[], int n){
//     int res = 0;
//     for(int i = 0; i < n; i++){
//         int cOne = 0, cZero = 0;
//         for(int j = i; j < n; j++){
//             if(arr[j] == 1)
//                 cOne++;
//             else
//                 cZero++;
//             if(cZero == cOne)
//                 res = max(res, j-i+1);
//         }
//     }
//     return res;
// }
//efficient solution
//O(n)
//convert this problem into finding longest subarray
//having sum 0 by replacing all 0 to -1

int longSub(int arr[], int n){
    unordered_map<int, int> mp;
    int pre_sum =0, res = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) 
            arr[i]= -1;}
    
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(pre_sum == 0) res = i +1;
        if(mp.find(pre_sum) == mp.end())
            mp.insert({pre_sum, i});
        if(mp.find(pre_sum) != mp.end()){
            res = max(res, i-mp[pre_sum]);
        }

    }
    return res;
    
}


int main(){
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longSub(arr, n);
    return 0;
}