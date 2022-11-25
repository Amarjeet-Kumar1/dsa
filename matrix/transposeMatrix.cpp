#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100;
void transposeMatrix(int arr[][MAX], int n){

    //we have to swap only upper triangle of matrix to get transpose
    // above digonal triangle
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(arr[i][j], arr[j][i]);
            
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
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

    transposeMatrix(arr, 4);
    return 0;
}