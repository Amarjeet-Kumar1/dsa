#include<iostream>
using namespace std;
class KStack{
    private:
        int *arr, *top, *next, cap, k, freeTop;
    public:
        KStack(int x, int y){
            cap = x;
            k = y;
            arr = new int[cap];
            top = new int[k];
            next = new int[cap];
            for(int i = 0; i < k; i++){
                top[i] = -1;
            }
            for(int i = 0; i < cap-1; i++){
                next[i] = i+1;
            }
            next[cap-1] = -1;
            freeTop = 0;
        }
        void push(int x, int ns){
            int i = freeTop;
            freeTop = next[i];
            next[i] = top[ns];
            top[ns] = i;
            arr[i] = x;
        }
        int pop(int sn){
            int i = top[sn];
            top[sn] = next[i];
            next[i] = freeTop;
            freeTop = i;
            return arr[i];
        }
        int topy(int sn){
            return arr[top[sn]];
        }
};
int main(){
    KStack st(5, 2);
    st.push(5, 1);
    st.push(6, 2);
    cout<<st.topy(1)<<" "<<st.topy(2);

    return 0;
}