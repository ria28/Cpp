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

string equallyRearranging(string str)
{
    string s = "WDL";
    unordered_map<char, int> map;
    for (int i = 0; i < str.size(); i++)
    {
        // if (map.find(str[i]) == map.end())
        // {
        //     map[str[i]] = 1;
        // }
        // else
        // {
        map[str[i]]++;
        // }
    }

    for (auto j : map)
    {
        cout << j.first << " " << j.second << "\n";
    }

    int n = str.size();
    // cout<<str<<" ";
    int i = 0; // wdl
    string res = "";
    while (n) // 5
    {
        // cout <<s[i] << " ";
        if (map[s[i]] > 0)
        {
            // cout << s[i] << " ";
            res += s[i];

            map[s[i]]--;
            n--;
        }
        i = (i + 1) % (s.size());
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "LDWDL";
    cout << equallyRearranging(str);
    return 0;
}