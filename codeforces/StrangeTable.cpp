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
#define vi vector<ll>
#define vii vector<vector<ll>>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int x;
        cin >> x;
        int cell_x = 0, cell_y = 0;
        cell_x = x % n;

        int fac = n-1-(cell_x-1);
        int diff =0;
        for (int i = 1; i <= m; i++)
        {
            int ele = (cell_x * i)+diff;
            if(ele == x)
            {
                cell_y = i;
                break;
            }
            diff += fac;            
        }

        // in_rows
        int ans =0;
        for(int i =1; i<cell_x;i++)
        {
            ans += cell_y + m;            
        }

        cout<<ans<<"\n";
    }
    return 0;
}