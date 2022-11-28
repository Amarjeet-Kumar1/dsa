#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//count frequencies of array elements

// IP {10, 12, 10, 15, 20, 12, 12}
// OP 10 3
//    12 3
//    15 1
//    20 1

//naive approach
//O(n2)

// void printFreq(int arr[], int n){
//     //check if it is not present previously

//     for(int i = 0; i < n; i++){
//         bool flag = false;
//         for(int j = i-1; j>=0; j--){
//             if(arr[i] == arr[j]){
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag == true) continue;

//         // if not present

//         int freq = 1;
//         for(int j = i+1; j<n; j++){
//             if(arr[j] == arr[i])
//                 freq++;
//         }
//         cout<<arr[i]<<" "<<freq<<endl;
//     }
// }

//second approach
//O(n2)


// void printFreq(int arr[], int n){
//     unordered_set<int> s;
//     for(int i = 0; i < n; i++)
//         s.insert(arr[i]);

//     for(auto it = s.begin(); it != s.end(); it++){
//         int count  = 0;
//         for(int i = 0; i < n; i++){
//             if(arr[i] == *it)
//                 count++;

//         }
//         cout<<*it<<" "<<count<<endl;
//     }
// }


//efficient solution
//using unordered_map
//array element as key and frequency as value\
// O(n) time and O(n) auxilary space 
//there is no specific order of element follows

void printFreq(int arr[], int n){
    unordered_map<int, int> mp;
    for(int i = 0 ; i < n; i++)
        mp[arr[i]]++;

    //mp[arr[i]]++; will search for arr[i] key
    //if it is not present it create a key-value pair arr[i] and default value as 0 and increment by 1
    //if present it increment it by 1

    for(auto x : mp)
        cout<<x.first<<" "<<x.second<<endl;
}

//ulternate solution
//to print element according to its first occurance
//traverse through array once and print frequency and markd frequency as -1
// so that same element is not printed multiple times

void printFreqSort(int arr[], int n){
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[arr[i]]++;

    for(int i = 0 ; i < n; i++){
        if(mp[arr[i]] != -1){
            cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
            mp[arr[i]] = -1;
        }
    }
}

int main(){
    int arr[] = {15, 12, 13, 12, 13, 13, 18};
    // int arr[]= {10, 10, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printFreqSort(arr, n);
    return 0;
}