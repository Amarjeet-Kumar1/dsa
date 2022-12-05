#include <iostream>
using namespace std;

// kmp algorithm to find a pattern in a text
// first we find longest prefix of pattern which is also suffix
void fillLps(string pat, int lps[])
{
    int n = pat.length(), len = 0, i = 1;
    lps[0] = 0;
    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void kmp(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    fillLps(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    // string txt = "ababcababaad", pat = "ababa";
    string txt = "aaaaab", pat = "aaaa";
    kmp(txt, pat);

    return 0;
}