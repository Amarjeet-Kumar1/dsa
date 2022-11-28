#include<iostream>
#include<unordered_set>
using namespace std;

//given two unsorted array
//find distinct intersection of these array

//IP {10, 15, 20, 15, 30, 20, 5}
//      {30, 5, 30, 80}

//OP 2 -- 30,5
 
//naive approach
//O(m*(m+n)) time O(1) aux space

// int intersectionArray(int a[], int b[], int m, int n){
//     int count = 0;
    

//     for(int i = 0; i < m; i++){
//         // check for duplicate
//         bool flag = false;
//         for(int j = i-1; j>=0; j--){
//             if(a[j] == a[i]){
//                 flag = true;
//                 break;
//                 }
//         }
//         if(flag == true) continue;

        
//         for(int j = 0; j < n; j++){
//             if(a[i] == b[j]){
//                 count++;
//                 break;
//             }
//         }

//     }
//     return count;
// }

//efficient solution
//using unordered_set
//O(m+n) time and O(m) auxilary space

int intersectionArray(int a[], int b[], int m, int n){
    unordered_set<int> s;
    for(int i = 0; i < m ; i++)
        s.insert(a[i]);

    int res = 0;
    for(int i = 0 ; i < n; i++){
        if(s.find(b[i]) != s.end()){
            res++;
            s.erase(b[i]);
        }
    }
    return res;
}


int main(){
    int a[] = {10, 15, 20, 15, 30, 30, 5};
    int b[] = {30, 5, 30, 80};
    // int a[] = {10, 20};
    // int b[] = {20, 30};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    cout<<intersectionArray(a, b, m, n);
    
    return 0;
}