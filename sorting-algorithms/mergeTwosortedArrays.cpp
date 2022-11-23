#include<iostream>
using namespace std;
void merge(int a[], int b[], int m, int n){
    int i = 0, j = 0;
    while(i<m && j< n){
        if(a[i] < b [j])
            cout<<a[i++]<<" ";
        else cout<<b[j++]<<" ";
    }
    while(i<m) cout<<a[i++]<<" ";
    while(j<n) cout<<b[j++]<<" ";
}
int main(){
    int a[]= { 2, 5, 7, 19, 25};
    int b[] = { 3, 8, 19, 30, 35, 40};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    merge(a, b, m, n);
    
    return 0;
}