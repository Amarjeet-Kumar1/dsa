#include<iostream>
using namespace std;


void snakePattern(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        if((i%2) == 0){
            for(int j = 0; j < 3; j++)
                cout<<arr[i][j]<<" ";
        }
        else {
            for(int j = 2; j >= 0; j--)
                cout<<arr[i][j]<<" ";
        }
    }
}
int main(){
    int arr[3][3] = {{1, 2, 3},
                     {6, 5, 4},
                     {9, 8, 7}};

    snakePattern(arr);
    return 0;
}