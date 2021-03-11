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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi arr(n);
    int cnt_5 = 0, cnt_0 = 0;
    int store = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 5)
            cnt_5++;
        else
            cnt_0++;
        if (cnt_5 % 9 == 0)
        {
            store = cnt_5;
        }
    }

    if (store == 0 && cnt_0 != 0)
    {
        cout << 0;
        // return 0;
    }
    else if (cnt_0 == 0)
    {
        cout << -1;
    }
    else
    {
        while (store--)
        {
            cout << 5;
        }
        while (cnt_0--)
        {
            cout << 0;
        }
    }

    return 0;
}