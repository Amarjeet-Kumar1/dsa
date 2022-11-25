#include<iostream>
using namespace std;
const int MAX = 100;

//matrix is row wise and column wise sorted

//begins from top right corner
//if x is same, print position and return
//if x is smaller, move left, cause matrix is column wise sorted and below it all element would automatically greater than x
//if x is greater, move down, cause matrix is row wise sorted and before it all element would automatically shorter than x

//time complexity is O(m+n)

void search(int arr[][MAX], int m, int n, int x){
    int i = 0, j = n-1;
    while(i < m && j >= 0){
        if(x == arr[i][j]){
            cout<<"Found at ("<<i<<", "<<j<<")";
            return;
        }
        else if(x < arr[i][j]){
            j--;
        }
        else i++;
    }
    cout<<"Not Found...";

}

int main(){
    int arr[4][MAX]= {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 19}};

    search(arr, 4, 4, 14);
    return 0;
}