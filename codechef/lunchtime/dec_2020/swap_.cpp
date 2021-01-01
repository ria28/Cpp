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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll one_S = 0, one_P = 0;
        string s, p;
        cin >> s >> p;
        bool f = true;
        int j = 1;
        for (int i = 0; i < n - 1 && j < n; i++)
        {
            if (s[i] != p[i])
            {
                if (s[j] == p[i])
                {
                    swap(s[i], s[j]);
                    i++;
                    j = i + 1;
                }
                else
                {
                    while (s[j] != p[i] && j < n)
                    {
                        j++;
                    }
                    if (s[j] != p[i])
                    {
                        f = false;
                        break;
                    }
                }
            }
            else
            {
                i++;
                j++;
            }
        }
        if (!f)
        {
            cout << "No\n";
            continue;
        }
        else
        {
            cout << "Yes\n";
            continue;
        }
    }

    return 0;
}