#include<iostream>
using namespace std;

//given an string find the leftmost character that repeats
// Ip str = "geeksforgeeks"
// Op 0 as g repeats 


//naive solution
//O(n2) time
// int firstRepeat(string str){
//     for(int i = 0; i < str.length(); i++){
//         for(int j = i+1; j < str.length(); j++){
//             if(str[i]==str[j])
//                 return i;
//         }
//     }
//     return -1;
// }

//O(n) two traversal
// int firstRepeat(string str){
//     int count[256] = {0};
//     for(int i = 0; i < str.length(); i++){
//         count[str[i]]++;
//     }
    
//     for(int i = 0; i < str.length(); i++){
//         if(count[str[i]] > 1)
//             return i;
//     }
//     return -1;

// }

//O(n) one traversal
int firstRepeat(string str){
    int res = INT_MAX;
    int fI[256];
    for(int i = 0; i < 256; i++)
        fI[i] = -1;
    //store first index in array of first occurance
    //if same element occures again check if the first index is minimum or not

    for(int i = 0; i < str.length(); i++){
        if(fI[str[i]] == -1)
            fI[str[i]] = i;
        else res= min(res, fI[str[i]]);
    }
    return (res == INT_MAX) ? -1 : res;
}


int main(){
    string str = "peeksforgeeks";
    cout<<firstRepeat(str);
    return 0;
}