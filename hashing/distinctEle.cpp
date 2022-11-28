#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//count distinct elements in every windows of a given array
// every window of size k (<= n)
//n-k-1 windows in an array of size n


//O((n-k)*k*k)

// void printDistinct(int arr[], int n, int k){
    
//     for(int i = 0; i <= n-k; i++ ){
//         int count = 0;
        
//         for(int j = 0; j < k; j++){
//             bool flag = false;
//             for(int p = 0; p <j ; p++){
//                 if(arr[i+j] == arr[i+p]){
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag == false) count++;
//         }
//         cout<<count<<" ";
//     }
// }


// void printDistinct(int arr[], int n, int k){
//     unordered_set<int> s;
//     for(int i = 0; i <= n-k; i++){
//         for(int j = i; j < i+k; j++){
//             s.insert(arr[j]);
//         }
//         cout<<s.size()<<" ";
//         s.clear();
//     }
// }

void printDistinct(int arr[],int n, int k){
    unordered_map<int, int> mp;
    for(int i = 0; i <k; i++){
            mp[arr[i]]++;
    }
    cout<<mp.size()<<" ";
    for(int i = k ; i < n; i++){
        mp[arr[i-k]]--;
        if(mp[arr[i-k]] == 0)
            mp.erase(arr[i-k]);
        mp[arr[i]]++;
        cout<<mp.size()<<" ";
    }
}

int main(){
    // int arr[] = { 10, 20, 20, 10, 30, 40, 10};
    int arr[] = { 10, 10, 10,10};
    // int arr[] = { 10, 10, 5, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printDistinct(arr, n, 3);
    return 0;
}