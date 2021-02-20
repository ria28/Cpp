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
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int q;
    cin >> q;
    string pat = "hackerrank";
    while (q--)
    {
        string txt;
        cin >> txt;

        int p_idx = 0;
        int t_idx = 0;
        while (p_idx < pat.size() && t_idx < txt.size())
        {
            // cout << txt[t_idx] << " ";
            if (pat[p_idx] == txt[t_idx])
            {
                p_idx++;
                t_idx++;
            }
            else
                t_idx++;
        }
        if (p_idx == pat.size())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}