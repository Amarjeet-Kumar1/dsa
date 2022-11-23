#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v = {2, 5, 1, 15, 4};
    cout<<"sorting vector in accending order"<<endl;
    sort(v.begin(), v.end());
    for(int i : v)
        cout<<i<<" ";
    
    return 0;
}