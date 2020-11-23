#include <iostream>
using namespace std;
bool solve(int n, int k, int x, int y)
{
    int cnt = 0;
    for (int i = x; i < n;)
    {
        if (cnt && i==x)
            break;
        if (i == y)
            return true;
        if (i == x && !cnt)
            cnt++;
        i = (i + k) % n;
    }
    return false;
}
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n >> k >> x >> y;
        if (solve(n, k, x, y))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}