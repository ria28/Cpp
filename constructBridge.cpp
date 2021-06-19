#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

/*  
    **arr 
    arr[0][1] = *(*(arr) +1 )

    arr[1][1] = *(*(arr + 1) +1)
*/


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m, vector<int>(2));
    unordered_map<int, int> map; // maps sum with ar idx
    vector<int> sum(m);
    int total_sum = 0;

    int req_sum = (n * (n + 1)) / 2;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        arr[i][0]=l;
        arr[i][1] = r;

        int r_sum = (r * (r + 1)) / 2;
        int l_sum = (l * (l - 1)) / 2;
        sum[i] = (r_sum - l_sum);
        map[sum[i]] = i;
        total_sum += sum[i];
    }

    vector<int> copy;
    copy = sum;

    if (total_sum < req_sum)
        cout << "-1\n";
    else
    {
        sort(sum.begin(), sum.end());

        int i = 0, n = sum.size(), res = n + 1;
        int strt, end;
        for (int j = 0; j < n; ++j)
        {
            req_sum -= sum[j];
            while (req_sum <= 0)
            {
                if (res > j - 1 + 1)
                {
                    strt = i;
                    end = j;
                    res = j - i + 1;
                }
                req_sum += sum[i++];
            }
        }
        
        int ans = 0;

        for (int j = strt; j <= end; j++)
        {
            int idx = map[sum[j]];
            int fir = arr[idx][0];
            int sec = arr[idx][1];
            // cout<<fir<<sec<<" ";
            ans += (sec - fir + 1);
        }
        cout << ans << "\n";
    }

    return 0;
}