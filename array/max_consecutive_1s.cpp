#include<iostream>

using namespace std;
int maxConsecutive1s(bool arr[], int n){
    int res = 0, temp = 0;
    for(int i = 0; i<n;i++){
        if(arr[i]==0)
            temp = 0;
        else {
            temp++;
            res = max(res, temp);
            
        }
    }
    return res;
}
int main(){
    bool arr[] = {1,0,1,1,1,0,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum consecutive 1's in this array is "<<maxConsecutive1s(arr, n);
    return 0;
}