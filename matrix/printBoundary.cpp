#include<iostream>
using namespace std;
const int MAX = 100;
void printBoundary(int arr[][MAX], int m, int n){
    int index = 0;
    if(m == 1){
        index = 0;
        while(index < n){
            cout<<arr[0][index++]<<" ";
        }
    } else if( n == 1){
        index = 0;
        while(index < m){
            cout<<arr[index++][n-1]<<" ";
        }
    } else {
    
        index = 0;
        while(index < n){
            cout<<arr[0][index++]<<" ";
        }
        index = 1;
        while(index < m){
            cout<<arr[index++][n-1]<<" ";
        }
        index = n - 2;
        while(index >= 0){
            cout<<arr[m-1][index--]<<" ";
        }
        index = m - 2;
        while(index > 0){
            cout<<arr[index--][0]<<" ";
        }
    }
    
}

int main(){
    int arr[4][MAX] = {{1, 2, 3, 4}, 
                       {2, 3, 4, 5}, 
                       {3, 4, 5, 6}, 
                       {4, 5, 6, 7}};

    printBoundary(arr, 4, 4);
    return 0;
}