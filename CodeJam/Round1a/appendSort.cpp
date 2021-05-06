#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

vector<pair<int, int>> countDigi(vi &arr)
{
    vector<pair<int, int>> ans(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        int ele = arr[i];
        int cnt = 0;
        int start = 0;
        while (ele)
        {
            if (ele / 10 == 0)
            {
                start = ele % 10;
            }
            int rem = ele % 10;
            ele = ele / 10;
            cnt++;
        }
        ans[i].first = start;
        ans[i].second = cnt;
    }

    // for (int i = 0; i < arr.size(); i++)
    //     cout << arr[i] << " ->" << ans[i].first << " " << ans[i].second << "\n";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<pair<int, int>> digi = countDigi(arr);
        int app = 0;
        for (int i = 1; i < digi.size(); i++)
        {
            if (arr[i] < arr[i - 1])
            {
                if (digi[i].first > digi[i - 1].first)
                {
                    int p = digi[i - 1].second - digi[i].second;
                    app += p;
                    arr[i] *= pow(10, p);
                    digi[i].second += p;
                    // cout<<app<<" "<<arr[i]<<"\n";
                }
                else if(digi[i].first == digi[i - 1].first && digi[i-1].second - digi[i].second ==1 && arr[i-1] %10 !=9)
                {
                    app += 1;
                }
                else
                {
                    int p = digi[i - 1].second - digi[i].second + 1;
                    app += p;
                    // cout<<p<<"<-";
                    arr[i] *= pow(10, p);
                    digi[i].second += p;
                    // cout<<app<<" "<<arr[i]<<"\n";
                }
            }
            else if (arr[i] == arr[i - 1])
            {
                app += 1;
            }
        }

        cout << app << "\n";
    }

    return 0;
}