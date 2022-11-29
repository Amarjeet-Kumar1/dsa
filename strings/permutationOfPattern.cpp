#include<iostream>
using namespace std;

//given a text string and pattern string, find if
//permutation of the pattern exists in the text at contiguos location
 
//Ip txt = "geeksforgeeks"
//   pat = "egek"
//OP Yes


//O(m*n)
// bool isPattern(string str, string ptr){
//     int countPtr[256]= {0};
//     for(int j = 0; j< ptr.length(); j++){
//             countPtr[ptr[j]]++;
//         }
//     for(int i = 0; i < str.length(); i++){
//         int count[256] = {0};
//         for(int j = i; j< i+ptr.length(); j++){
//             count[str[j]]++;
//         }
//         bool flag = false;
//         for(int j = 0; j < 256; j++)
//             if(count[j] != countPtr[j])
//                 flag = true;
//         if(flag == false)
//             return true;

//     }
//     return false;
// }

//window sliding technique
//O(txt.length)
bool isPattern(string txt, string pat){
    int countTxt[256] = {0}, countPat[256] = {0};
    for(int i = 0; i < pat.length(); i++){
        //count of first window of txt
        countTxt[txt[i]]++;
        //count of char of pattern
        countPat[pat[i]]++;
    }
    //number of window is (txt.length - pat.length)
    for(int i = pat.length(); i < txt.length(); i++){
            //check if current window is anagram or not
            bool flag = false;
            for(int j = 0; j < 256; j++){    
                if(countTxt[j] != countPat[j])
                    flag = true;
            }
            if(flag == false) return true;

            //if not
            //add next char in count
            countTxt[txt[i]]++;
            //remove first char of prev window
            countTxt[txt[i-pat.length()]]--;
    }
    return false;
}
int main(){
    string str = "geeksforgeeks";
    string ptr = "rfo";
    if(isPattern(str, ptr))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}