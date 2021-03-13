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

void lcs(string str1, string str2)
{
    vii dp(str1.size() + 1, vi(str2.size() + 1, 0));
    int max_ = INT_MIN;

    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] != str2[j - 1])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            max_ = max(max_, dp[i][j]);
        }
    }
    // for (int i = 0; i <= str1.size(); i++)
    // {
    //     for (int j : dp[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout<<"\n";
    // }
    cout << max_;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str2 = "xyzabcp";
    string str1 = "pqabcxy";
    lcs(str1, str2);
    return 0;
}