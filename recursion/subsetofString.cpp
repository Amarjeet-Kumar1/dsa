#include<iostream>
using namespace std;
void subStr(string str, string curr = "", int index = 0){
    if(index == str.length())
        {
        cout<<curr<<" ";
        return;
        }
    subStr(str, curr, index+1);
    subStr(str, curr+str[index], index+1);
}
int main(){
    string str;
    cin>>str;
    subStr(str);
    return 0;
}