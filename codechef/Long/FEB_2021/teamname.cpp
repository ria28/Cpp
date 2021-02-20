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
#define all(v) v.begin(), v.end()

int common(vector<char> arr1, vector<char> arr2)
{
    unordered_set<char> set(all(arr1));
    int cnt = 0;
    for (auto x : arr2)
        if (set.find(x) != set.end())
            cnt++;
    return cnt;
}
int solve()
{
    int n;
    int cnt = 0;
    cin >> n;
    unordered_map<string, vector<char>> map;
    string str;
    f_loop(i,0,n)
    {
        cin >> str;
        if (str.length() > 0)
            map[str.substr(1)].push_back(str[0]);
    }
    for (auto i : map)
    {
        for (auto j : map)
        {
            if (i.first != j.first)
            {
                int c = common(i.second, j.second);
                cnt += (i.second.size() - c) * (j.second.size() - c);
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}