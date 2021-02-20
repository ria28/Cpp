#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define sortAll(arr) sort(arr.begin(), arr.end());

int fetch(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end())
        return it - v.begin();
    return -1;
}

int solve()
{
    ll n;
    cin >> n;

    vi wt(n);
    vi X(n);
    f_loop(i, 0, n)
    {
        cin >> wt[i];
        X[i] = wt[i];
    }
    sortAll(X);
    vi len(n);
    f_loop(i, 0, n)
    {
        cin >> len[i];
    }

    vi pos(n);
    f_loop(i, 0, n)
    {
        pos[i] = i;
    }

    int hits = 0;
    f_loop(j, 1, n)
    {
        int idx = fetch(wt, X[j]);
        int prev = pos[fetch(wt, X[j - 1])];
        int curr = idx;

        while (prev >= curr)
        {
            curr += len[idx];
            pos[idx] = curr;
            hits++;
        }
    }
    return hits;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}