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

int minimumDeleteSum(string s1, string s2)
{
    int n1 = s1.size(); // eat _
    int n2 = s2.size(); // sea _

    vii dp(n1 + 1, vi(n2 + 1, 0));

    for (int i = n1; i >= 0; i--)
    {
        for (int j = n2; j >= 0; j--)
        {
            if (i == n1 && j == n2)
                dp[i][j] = 0;
            else if (i == n1)
            {
                dp[i][j] = dp[i][j + 1] + (int)s2[j];
            }
            else if (j == n2)
            {
                dp[i][j] = dp[i + 1][j] + (int)s1[i];
            }
            else
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j]= min(dp[i][j + 1] + (int)s2[j] ,dp[i + 1][j] + (int)s1[i]);
                }
            }
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j : dp[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2;
    cin >> str1 >> str2;
    minimumDeleteSum(str1, str2);
    return 0;
}


// "xnbteodleejrzeo"
// "gaouojqkkk"