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

int hr, mi;
vi a = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
bool check(int h, int m) // check refection
{
    if (a[h % 10] == -1 || a[h / 10] == -1 || a[m % 10] == -1 || a[m / 10] == -1)
        return false;
    int m_ref = a[h % 10] * 10 + a[h / 10];
    int h_ref = a[m % 10] * 10 + a[m / 10];
    return h_ref < hr && m_ref < mi;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int hh, mm;
        scanf("%d%d", &hr, &mi);
        scanf("%d:%d", &hh, &mm);

        while (hh != 0 || mm != 0)
        {
            if (check(hh, mm))
                break;

            if (mm == mi - 1)
            {
                hh = (hh + 1) % hr;
            }
            mm = (mm + 1) % mi;
        }

        cout << (hh / 10) << (hh % 10) << ":" << (mm / 10) << (mm % 10) << "\n";
    }
    return 0;
}