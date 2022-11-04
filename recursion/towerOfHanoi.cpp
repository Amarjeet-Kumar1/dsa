#include<iostream>
using namespace std;
void TOH(int n, char A, char B, char C){
    if(n==1){
        cout<<"move disk 1 from "<<A<<" to "<<C<< endl;
        return;
    }
   TOH(n-1, A, C, B);
   cout<<"move disk "<<n<<" from "<<A<<" to "<<C<< endl;
   TOH(n-1, B, A, C);
}
int main(){
    int n;
    cout<<"Enter number of disk in A: ";
    cin>>n;
    TOH(n, 'A', 'B', 'C');

    return 0;
}