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

    string str;
    getline(cin, str);
    // cout<<str;
    vector<bool> vis(26, false);
    for (auto s : str)
    {
        if (s == ' ')
            continue;
        // cout << s;
        if (s >= 'A' && s <= 'Z')
            vis[s - 'A'] = true;
        else
            vis[s - 'a'] = true;
    }
    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
        {
            cout << "not pangram";
            return 0;
        }
    }
    cout << "pangram";
    return 0;
}