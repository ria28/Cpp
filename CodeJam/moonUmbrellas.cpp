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

    int t;
    cin >> t;
    int T = 1;
    while (T <= t)
    {
        int cj, jc;
        cin >> cj >> jc;
        string str;
        cin >> str;

        int cost = 0;
        string sub = "";
        for (int i = 0; i < str.size(); i++)
        {
            while (str[i] == '?' && i < str.size())
            {
                i++;
            }
            sub += str[i];
        }

        for (int i = 1; i < sub.size(); i++)
        {
            if (sub[i] == 'C' && sub[i - 1] == 'J') // JC
            {
                cost += jc;
            }
            else if (sub[i] == 'J' && sub[i - 1] == 'C') // CJ
            {
                cost += cj;
            }
        }

        cout << "Case #" << T << ": " << cost << "\n";

        T++;
    }

    return 0;
}
