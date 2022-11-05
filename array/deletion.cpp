#include<iostream>
using namespace std;
int deleteEle(int arr[], int n, int x){
    int i;
    for(i = 0; i<n;i++){
        if(arr[i] == x)
            break;
    }
    if(i==n)
        return n;
    for(int j = i; j<n-1; j++){
        arr[j] = arr[j+1];
    }
    return n-1;
}
int main(){
    int arr[]={10, 20, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    int deletion = deleteEle(arr, n, x);
    if(deletion == n-1){
        cout<<x<<" deleted successfully!!"<<endl;
        cout<<"New array is: ";
        for(int i= 0; i<n-1;i++){
            cout<< arr[i]<<" ";
        }
    }
    else if( deletion == n){
        cout<<"Element not found!!";
    }
    
    return 0;
}