#include<iostream>
#include<cmath>
using namespace std;
int maxValue(int a, int b, int c){
    return max(max(a,b), max(b,c));
}

int maxPiece(int n, int a, int b, int c){
    if(n==0)
        return 0;
    if(n<0)
        return -1;
    int res = maxValue(maxPiece(n-a, a, b, c), maxPiece(n-b, a, b, c), maxPiece(n-c, a, b, c));
    if(res== -1)
        return -1;
    return res+1;
}

int main(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    cout<<maxPiece(n,a,b,c);
    return 0;
}