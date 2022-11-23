#include<iostream>
#include<algorithm>

struct Point
{
    int x, y;
};

bool myCom(Point p1, Point p2)
{
    return (p1.y < p2.y);
}

using namespace std;

int main(){
    Point arr[] = {{3, 10}, {2, 8}, {5, 1}};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+n, myCom);
    for(Point ar : arr){
        cout<<ar.x<<" ";
        cout<<ar.y<<endl;
        
        }
    return 0;
}