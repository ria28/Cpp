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
        int n;
        cin >> n;
        vii arr(n, vi(n));
        int rows = 0;
        int trace = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> set;
            bool isRep = false;
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (i == j)
                {
                    trace += arr[i][j];
                }
                if (set.find(arr[i][j]) != set.end())
                {
                    isRep = true;
                    break;
                }
                else
                {
                    set.insert(arr[i][j]);
                }
            }
            if (isRep)
                rows++;
        }
        int col = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> set2;
            bool isRep = false;
            for (int j = 0; j < n; j++)
            {
                if (set2.find(arr[j][i]) != set2.end())
                {
                    isRep = true;
                    break;
                }
                else
                {
                    set2.insert(arr[j][i]);
                }
            }
            if (isRep)
                col++;
        }

        cout << "Case #" << T << ": " << trace << " " << rows << " " << col << "\n";
        T++;
    }
    return 0;
}