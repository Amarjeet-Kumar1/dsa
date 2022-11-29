#include<iostream>
using namespace std;


//check if two string are rotations of each other
//clock wise or anticlock wise

//IP str = "ABCD" str2 = "CDAB"
//OP True

// if we concatenate a string with itself and search s2 in 
// this concatenate string if s2 is present than s2 is rotation of s1.

bool areRotations(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
    s1 = s1 + s1;
    return (s1.find(s2) != string::npos);
}

int main(){
    string s1 = "ABCD", s2 = "CDAB";
    if(areRotations(s1, s2))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}