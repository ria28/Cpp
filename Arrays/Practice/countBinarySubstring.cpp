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

int countBinarySubstrings(string s)
{
    int curr = 1;
    int prev = 0;
    int res = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            curr++;
        else
        {
            res += min(prev, curr);
            prev = curr;
            curr = 1;
        }
    }
    return res + min(prev, curr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}