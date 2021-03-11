#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

void minWays(string s, string exp)
{
    // make a dp boolean array for palin
    int n = s.size();

    vii dpT(n, vi(n, 0));
    vii dpF(n, vi(n, 0));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                if (s[i] == 'T')
                {
                    dpT[i][j] = 1;
                    dpF[i][j] = 0;
                }
                else
                {
                    dpT[i][j] = 0;
                    dpF[i][j] = 1;
                }
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    char operator_ = exp[k];
                    int ltc = dpT[i][k];     // left true count
                    int rtc = dpT[k + 1][j]; // right true count
                    int lfc = dpF[i][k];     // left false count
                    int rfc = dpF[k + 1][j]; // right false count
                    if (operator_ == '&')
                    {
                        dpT[i][j] += ltc * rtc;
                        dpF[i][j] += (lfc * rfc) + (lfc * rtc) + (ltc * rfc);
                    }
                    else if (operator_ == '|')
                    {
                        dpT[i][j] += (ltc * rtc) + (lfc * rtc) + (ltc * rfc);
                        dpF[i][j] += lfc * rfc;
                    }
                    else // xor ^
                    {
                        dpT[i][j] += (ltc * rfc) + (lfc + rtc);
                        dpF[i][j] += (ltc * rtc) + (lfc * rfc);
                    }
                }
            }
        }
    }

    for (int i = 0; i < dpT.size(); i++)
    {
        for (auto j : dpT[i])
            cout << j << " ";
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < dpF.size(); i++)
    {
        for (auto j : dpF[i])
            cout << j << " ";
        cout << "\n";
    }

    // return dpT[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1 = "TTFT";
    string str2 = "|&^";
    minWays(str1, str2);
    return 0;
}