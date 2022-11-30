#include<iostream>
using namespace std;

//contruct longest proper prefix suffix array for kmp algo
//IP "abacabad"
//Op  00101230

//naive solution
//O(n3)
// int longPreSuf(string str, int n){
//     for(int len = n-1; len > 0; len--){
//         bool flag = true;
//         for(int i = 0; i < len; i++){
//             // first element of suffix (n-len)
//             if(str[i] != str[n-len+i]){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag == true) return len;
//     }
//     return 0;
// }
// void fillLPS(string str, int lps[]){
//     for(int i = 0; i < str.length(); i++)
//         lps[i] = longPreSuf(str, i+1);
// }


//efficient solution

// void longPreSuf(string str, int lps[]){
//     lps[0] = 0;
//     for(int i = 1; i < str.length(); i++){
//         int len = lps[i-1];
//         if(str[i] == str[len])
//             lps[i] = len +1;
//         else if(len == 0)
//             lps[i] = 0;
//         else {
//             len = lps[len-1];
//             if(str[i] == str[len])
//                 lps[i] = len +1;
//         }
//     }
// }

// or another implementation
//O(n)
void longPreSuf(string str, int lps[]){
    int n = str.length(), len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len == 0){
            lps[i] = 0;
            i++;
            } else {
            len = lps[len - 1];
            }
        }
    }
}


int main(){
    string str = "abacabad";
    // string str = "abbabb";
    int l = str.length();
    int lps[l];
    longPreSuf(str,lps);
    for(int x : lps)
        cout<<x<<" ";
    return 0;
}