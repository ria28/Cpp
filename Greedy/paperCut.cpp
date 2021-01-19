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

//https://www.geeksforgeeks.org/paper-cut-minimum-number-squares/

// gives wrong ans for 11 X 13 , 36 X 30-----> Dynamic Programming

void solve(int l, int b, int cnt)
{
    // cout << l << " " << b;
    if (l == b)
    {
        cout << cnt;
        return;
    }
    else if (l == 0 || b == 0)
    {
        cout << cnt;
        return;
    }

    int mi = min(l, b);
    if (mi != l)
    {
        cnt += l / mi;
        // int fac = l / mi;
        // l -= mi*fac;
        l = l % mi;
    }
    else
    {
        cnt += b / mi;
        // int fac = b / mi;
        // b -= mi*fac;
        b = b % mi;
    }

    solve(l, b, cnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l, b;
    cin >> l >> b; // 13 X 29 ---> min no of squares = 9
    solve(l, b, 0);
    return 0;
}