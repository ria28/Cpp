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

vi ans;
int cnt = 0;
void count(string str, int idx, string asf)
{
    // cout<<asf<<" ";
    if (idx >= str.size())
    {
        cnt++;
        // cout << asf << " ";
        return;
    }

    if (str[idx] == '0')
    {
        // cnt = 0;
        return;
    }

    if (idx > 0 && str[idx] == '0' && str[idx - 1] == '0')
    {
        cnt = 0;
        return;
    }

    count(str, idx + 1, asf + char('a' + (str[idx] - '0')));
    if (idx + 1 < str.size() && stoi(str.substr(idx, 2)) < 26 && str[idx] != '0')
    {
        count(str, idx + 2, asf + char('a' + stoi(str.substr(idx, 2))));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<char('a'+25);
    string str;
    cin >> str;
    count(str, 0, "");
    if (str.size() == 1 && str[0] == '0' || cnt == 0)
    {
    }
    else
    {
        cout << cnt << "\n";
    }
    return 0;
}