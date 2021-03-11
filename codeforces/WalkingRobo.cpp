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
    ll t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int cntL = 0, cntR = 0, cntU = 0, cntD = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'L')
                cntL++;
            else if (str[i] == 'R')
                cntR++;
            else if (str[i] == 'U')
                cntU++;
            else
                cntD++;
        }

        int min_lr = min(cntL, cntR);
        int min_up = min(cntU, cntD);
        string ans = "";
        if (min_lr == 0 && min_up == 0)
        {
            cout << 0 << "\n";
        }
        else if (min_lr == 0)
        {
            cout << "2\nUD\n";
        }
        else if (min_up == 0)
        {
            cout << "2\nLR\n";
        }
        else
        {
            int u = min_up;
            while (u--)
            {
                ans += "U";
            }
            int l = min_lr;
            while (l--)
            {
                ans += "L";
            }

            int d = min_up;
            while (d--)
            {
                ans += "D";
            }
            int r = min_lr;
            while (r--)
            {
                ans += "R";
            }

            cout << ans.size() << "\n"
                 << ans << "\n";
        }
    }
    return 0;
}