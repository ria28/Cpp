#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    // 0100111001
    // 1010100110
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << "\n";
            continue;
        }
        int cnt = 0;
        int i = 0;
        bool same = false;
        while (i < a.size())
        {
            if (a[i] != b[i])
            {
                if (!same)
                {
                    cnt++;
                    same = true;
                }
                a[i] = b[i];
                i += 2;
            }
            else
            {
                same = false;
                i += 2;
            }
        }
        // cout << cnt << " ";
        same = false;
        i = 1;
        while (i < a.size())
        {
            if (a[i] != b[i])
            {
                if (!same)
                {
                    cnt++;
                    same = true;
                }
                a[i] = b[i];
                i += 2;
            }
            else
            {
                i += 2;
                same = false;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}