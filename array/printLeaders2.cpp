#include<iostream>
using namespace std;
void printLeader(int arr[], int n){
    int curr_lead = arr[n-1];
    cout<<curr_lead<<" ";
    for(int i = n-2; i>=0;i--){
        if(curr_lead < arr[i]){
            curr_lead = arr[i];
            cout<<curr_lead<<" ";
        }
    }
}
int main(){
    int arr[]= {7,10,4,3,6,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Leaders of this array is: ";
    printLeader(arr,n);
    return 0;
}