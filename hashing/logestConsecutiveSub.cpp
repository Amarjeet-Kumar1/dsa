#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
//lenght of longest subsequece that has consecutive integers
// Ip arr[] = {1, 9, 3, 4, 2, 20}
//Op 4

//Ip arr[] = {8, 20, 7, 30}
//op 2


//method 1
//using sort
//O(nlogn);

// int consecutiveSub(int arr[], int n){
//     sort(arr, arr+n);
//     int res = 1, curr = 1;
//     for(int i = 1; i < n; i++){
//         if(arr[i] == arr[i-1]+1)
//             curr++;
//         else {
//             res = max(res, curr);
//             curr = 1;
//         }
//     }
//     //when all the element are consecutive
//     res = max(res, curr);
//     return res;
// }


//effective solution
//O(n) time

int consecutiveSub(int arr[], int n){
    int res = 0;
    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(arr[i]);
    }
    for(int i = 0; i < n ; i++){
        //check if it is starting point of consecutive sequence or not

        if(s.find(arr[i]-1) == s.end()){
            int curr = 1;
            while(s.find(arr[i]+curr)!= s.end()){
                curr++;
            }
            res = max(res, curr);
        }

    }
    return res;
}


int main(){
    int arr[] = {1, 9, 3, 4, 2, 20};
    // int arr[] = {8, 20, 7, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<consecutiveSub(arr, n);
    return 0;
}