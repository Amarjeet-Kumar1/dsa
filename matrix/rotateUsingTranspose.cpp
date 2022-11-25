#include<iostream>
#include<algorithm>
using namespace std;
 const int MAX = 100;

void rotate(int arr[][MAX], int n){
        //first transpose given matrix
         for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(arr[i][j], arr[j][i]);
            
        }
    }

        //reverse individual columns

        for(int i = 0; i < n; i++){
            int low = 0, high = n-1;
            while(low < high){
                swap(arr[low][i], arr[high][i]);
                low++;
                high--;
            }
        }

}



int main(){
    int arr[4][MAX]= {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};

    rotate(arr, 4);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}