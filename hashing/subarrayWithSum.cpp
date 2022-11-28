#include<iostream>
#include<unordered_set>
using namespace std;

//if suarray with given sum present in an array
//IP {5, 8, 6, 13, 3, -1}
//          ---------
// Sum = 22
//Op Yes

//O(n) time O(n) space

bool isSum(int arr[], int n,int sum){
    unordered_set<int> s;
    int pre_sum = 0;
    for(int i = 0; i < n; i++){
        pre_sum += arr[i];
        if(s.find(pre_sum-sum) != s.end())
            return true;
        if(pre_sum == sum)
            return true;
        s.insert(pre_sum);
    }
    return false;
}

int main(){
    int arr[] = {5, 8, 6, 13, 3, -1};
    int sum = 22;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isSum(arr, n, sum))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}