#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

void encode(string str)
{
    vector<int> dp(str.size());
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++)
    {
        if (str[i - 1] == 0 && str[i] == 0)
        {
            dp[i] = 0;
        }
        else if (str[i - 1] == 0 && str[i] != 0)
        {
            dp[i] = dp[i - 1];
        }
        else if (str[i - 1] != 0 && str[i] == 0)
        {
            if (str[i - 1] == 1 || str[i] == 2)
            {
                dp[i] = i >= 2 ? dp[i - 2] : 1;
            }
            else
            {
                dp[i] = 0;
            }
        }
        else // both non zero
        {
            int no = stoi(str.substr(i - 1, 2));
            if (no <= 26)
            {
                dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
    }
    cout << dp[str.size() - 1];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string str = "21123";
    // a =1 , b =2 , c=3 , d =4 , e =5 , f =6 .........x = 24 , y=25, z = 26;
    // 0 --> 0
    encode(str);
    return 0;
}