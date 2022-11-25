#include<iostream>
#include<algorithm>
using namespace std;
 const int MAX = 100;
void rotate(int arr[][MAX], int m, int n){
    int temp[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // swap(arr[i][j], arr[m-1-i][i]);
            temp[i][j] = arr[j][n-1-i];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = temp[i][j];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[4][MAX]= {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};

    rotate(arr, 4, 4);
    return 0;
}