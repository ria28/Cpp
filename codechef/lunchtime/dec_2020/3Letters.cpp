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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_map<char, int> map;
        for (ll i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) == map.end())
            {
                map[s[i]] = 1;
            }
            else
            {
                map[s[i]]++;
            }
        }
    }
    return 0;
}