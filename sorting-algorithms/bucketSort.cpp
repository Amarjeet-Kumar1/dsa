#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//bucket sort, useful for uniformly distributed input over a rangr

void bucketSort(int arr[], int n, int k){
    //find maximum element
    int max_val = arr[0];
    for( int i = 1; i < n; i++)
        max_val = max(arr[i], max_val);
    max_val++;

    //declear array of vector, having fixed row k
    //each row is vector of variable length
    
    vector<int> bkt[k];

    //fill bucket with respective element
    //(k*arr[i])/max_val gives index of suitalbe bucket

    for(int i = 0; i < n; i++){
        int bi = (k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }

    //sort bucket
    for(int i = 0; i < k; i++)
        sort(bkt[i].begin(), bkt[i].end());

    //join bucket

    int index = 0;
    for(int i= 0; i < k; i++)
        for(int j = 0; j < bkt[i].size(); j++)
            arr[index++] = bkt[i][j];
}

int main(){
    int arr[] = {30, 40, 10, 80, 5, 12, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr, n, 4);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}