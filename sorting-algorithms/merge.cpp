#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    //create two auxullary arrays
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];

    //fill their respective value to it

    for(int i = 0; i < n1; i++)
        left[i] = arr[l+i];
    for(int j = 0; j < n2; j++)
        right[j] = arr[m+1+j];

    //initilize index of left and right array
    int i = 0, j = 0;
    //initilize index of merged array or original array
    int k = l;
    //start merging by checking which element is smaller than other
    while(i< n1 && j < n2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else arr[k++] = right[j++];

    }
    // if any element left in any aux array
    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];
    
}
int main(){
    int arr[] = {2, 5, 10, 20, 25, 1, 3, 15, 20, 30, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    merge(arr, 0, 4, n);
    for(int x : arr)
        cout<<x<< " ";

    
    return 0;
}