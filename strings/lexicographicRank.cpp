#include<iostream>
using namespace std;

//find lexicographic rank
//after sorting permutation of a string in increasing order
//and at which rank given string comes
///this rank is called lexicographic rank

//Ip str= "BAC"
//OP 3
//ex string     lex. rank
//  ABC         1
//  ACB         2
//->BAC         3
//  BCA         4
//  CAB         5
//  CBA         6
int fact(int n){
    if(n==1 || n == 0)
        return 1;
    return n*fact(n-1);
}
int lexRank(string str){
    int rank = 1;
    int n = str.length();
    int mul = fact(n);
    int count[256]={0};
    for(int i = 0; i < n; i++)
        count[str[i]]++;

    //cummulative sum, count less or equals to current
    
    for(int i = 1; i < 256; i++)
        count[i] = count[i-1]+count[i];
    
    for(int i = 0; i <  n; i++){
        mul = mul/(n-i);
        rank = rank + count[str[i]-1]*mul;
        for(int j = str[i]; j<256; j++)
            count[j]--;
    }
    return rank;
}

int main(){
    string str = "bca";
    cout<<lexRank(str);
    return 0;
}