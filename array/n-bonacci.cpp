#include<iostream>
using namespace std;

void nBonacci(int n, int m){
    int arr[m];
    for(int i = 0; i<m; i++){
        
        if(i==n-1)
            arr[i]=1;
        else 
            arr[i] = 0;
        
        if(i>n-1){
        for(int j = i-1; j > i-n-1; j--){
            arr[i] += arr[j];
        }
        }
        cout<< arr[i] << " ";
    }
}
int main(){
    int n = 3, m = 8;
    nBonacci(n,m);


    return 0;
}