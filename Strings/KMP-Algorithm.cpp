// KNUTH-MORIS-PRATT ALGORITHM
// SEARCHES PATTERN IN O(N) TIME
#include <iostream>
#include <string.h>
using namespace std;

// LONGEST PREFIX SUFFIX ARRAY lps[n]
void computeLPS(string patt, int *lps)
{
    lps[0] = 0; // always be 0

    int i = 1, j = 0;
    while (i < patt.size())
    {
        if (patt[j] == patt[i])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                j = lps[j - 1];
        }
    }
}

void KMP_Search(string text, string patt)
{
    int N = text.size();
    int M = patt.size();
    int lps[M];

    computeLPS(patt, lps);

    // for (int i = 0; i < M; i++)
    //     cout << lps[i];

    int i = 0; //text
    int j = 0; // pattern

    while (i < N)
    {

        if (patt[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            // cout << M<<"\n";
            int startIndex = (i - j);
            j = lps[j - 1];
            cout << startIndex;
        }
        else if (patt[j] != text[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main(int args, char **argc)
{
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    KMP_Search(text, pattern);
}