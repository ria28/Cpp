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
vi dp;
int pairing(int n)
{
    for (int i = 3; i <= n; i++)
    {

        dp[i] = dp[i - 1] + (i - 1)*dp[i - 2];
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dp.resize(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    cout << pairing(n);
    return 0;
}