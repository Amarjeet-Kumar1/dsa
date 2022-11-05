#include<iostream>
using namespace std;
void printLeader(int arr[], int n){
    for(int i = 0; i<n; i++){
        bool flag = false;
        for(int j = i+1; j<n;j++){
            if(arr[i]<=arr[j]){
                flag = true;
                break; 
            }
        }
        if(flag == false)
            cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]= {7,10,4,3,6,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Leaders of this array is: ";
    printLeader(arr,n);
    return 0;
}