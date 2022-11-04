#include<iostream>
#include<string>
using namespace std;

bool isPal(string str, int s, int e ){
    if(s >= e)
        return true;
    if(str[s] != str[e])
        return false;
    return isPal(str, s+1, e-1);

}
int main(){
    string str;
    int  s=0;
    cin>>str;
    int e =str.length()-1;
    if(isPal(str, s, e))
       {
         cout<<"Yes";
         }
    else {
        cout<<"No";
        }
    
    return 0;
}