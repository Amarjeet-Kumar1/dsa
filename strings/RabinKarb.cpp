#include<iostream>
using namespace std;
const int d = 256;

//rabin karb algorithm to search pattern in text
//its better than naive solution in avg case
//it's first compare hash value of pattern with first window
// if it is same then its compare individual char
//and slide the window

void RBSearch(string txt, string pat){
    int n = txt.length(), m = pat.length();
    

    // compute (d m-1)%q;
    //q = any big prime number to avoid excessive spurious hits and integer overflow

    int q = INT_MAX;
    int h = 1;
    
    for(int i = 0; i < m-1; i++)
        h = (h*d)%q;

    //compute the hash value for pattern and first window
    //using horner's rule for polynomial
    //h = par[0]*d (m-1) + pat[1]*d (m-2)+ ... +pat[m-1]*d(0)
    int p = 0,  t = 0;
    for(int i = 0; i < m; i++){
        p = (p*d + pat[i])%q;
        t = (t*d + txt[i])%q;
    }

    //if hash value is same compare their char
    //check for spurious hit
    for(int i = 0; i <= n-m; i++){
        if(p == t){
            bool flag = true;
            for(int j =0; j < m; j++)
                if(txt[i+j] != pat[j]){
                    flag = false;
                    break;
                }
                if(flag == true) cout<<i<<" ";

        }
        //compute hash value for next window using current hash value
        if(i < n-m){
            t = (d*(t-txt[i]*h) + txt[i+m])%q;
            if(t < 0) t = t + q;

        }
    }

}

int main(){
    string str = "amarjeetkuamaramar";
    string pat = "amar";
    // string str = "baaaa", pat = "aa";
    RBSearch(str, pat);
    return 0;
}