#include<iostream>
using namespace std;

//given two strings, check if they are anagram of each other
//if they have same set of character and every set of charcter have same frequency in both array
//basically we need to check if both string is permutation of each other or not

//IP s1 = "geeks", s2 = "ekegs"
//Op yes

//IP s1 = "aabcd", s2 = "abbcd"
//OP No

//O(n + Alphabet_size) time
//O(Alphabet_size) aux space

bool isAnagram(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    
    int count[256] = {0};
    for(int i = 0; i < s1.length(); i++)
        count[s1[i]]++;
    
    for(int i = 0; i < s2.length(); i++)
        count[s2[i]]--;

    for(int i = 0; i < 256; i++)
        if(count[i] != 0)
            return false;
    
    return true;
    

    
}

int main(){
    string s1 = "amar";
    // string s2 = "raam";
    string s2 = "aman";
    if(isAnagram(s1, s2))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}