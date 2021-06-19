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

int ans = 0;
void func(int N, int x1, int y1, int x2, int y2)
{
    if (y1 <= 0 || y2 <= 0 || x1 > N || x2 > N)
        return;

    if (x1 == N && x2 == N && y1 == y2)
    {
        cout << "ans: ";
        cout << x1 << " " << y1 << " - " << x2 << " " << y2 << "\n";
        ans++;
        return;
    }

    if (x1 == x2 && y1 == y2)
        return;
    cout << x1 << " " << y1 << " - " << x2 << " " << y2 << "\n";
    func(N, x1 + 1, y1 + 1, x2 + 1, y2 + 1);
    func(N, x1 + 1, y1 - 1, x2 + 1, y2 - 1);
    func(N, x1 + 1, y1 - 1, x2 + 1, y2 + 1);
    func(N, x1 + 1, y1 + 1, x2 + 1, y2 - 1);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int N = 5;
    int x = 3;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (i != j)
                func(N, 1, i, 1, j);
        }
    }
    cout << ans;
    return 0;
}