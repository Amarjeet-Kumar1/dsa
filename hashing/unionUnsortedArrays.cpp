#include<iostream>
#include<unordered_set>
using namespace std;

//count the element in union of two unsorted arrays
//only distinct element in union


//efficient solution
//using unordered_set
//time O(m+n), space O(m+n)
int unionArray(int a[], int b[], int m, int n){
    unordered_set<int> s;
    for(int i = 0; i < m; i++)
        s.insert(a[i]);
    
    for(int i = 0; i < n; i++)
        s.insert(b[i]);
    
    return s.size();
    
}

int main(){
    int a[] = {15, 20, 5, 15};
    int b[] = {15, 15, 15, 20, 10};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    cout<<unionArray(a, b, m, n);
    
    return 0;
}