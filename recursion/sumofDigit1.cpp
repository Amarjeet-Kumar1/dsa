#include<iostream>
using namespace std;

int sum(int n, int s=0){
    if(n<=0)
        return s;
    return sum(n/10, s+n%10);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}