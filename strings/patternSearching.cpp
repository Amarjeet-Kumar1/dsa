#include <iostream>
using namespace std;

// find all index in text where given pattern is present
// IP txt = "ABABAB"
//   pat = "ABAB"
// Op 0 2

// naive solution
// O((m-n)*n) time
//  void patternSearch(string txt, string pat){
//      int m = txt.length(), n = pat.length();
//      for(int i = 0; i < m-n+1; i++){
//          int j;
//          for(j = 0; j < n; j++){
//              if(txt[i+j] != pat[j])
//                  break;
//          }
//          if(j == n) cout<<i<<" ";
//      }
//  }

// if all elements of pattern are different
// O(m)
void patternSearch(string txt, string pat)
{
    int m = txt.length(), n = pat.length();
    for (int i = 0; i < m - n + 1;)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == n)
            cout << i << " ";
        if (j == 0)
            i++;
        else
            i = i + j;
        // as all element are different a new window can't be
        // started before i+j
    }
}

int main()
{
    // string txt = "ABABAB", pat = "ABAB";
    // string txt = "AAAAA", pat = "AAA";
    string txt = "ABCABCD", pat = "ABCD";
    patternSearch(txt, pat);
    return 0;
}