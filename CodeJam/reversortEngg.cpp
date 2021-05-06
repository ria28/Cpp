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

vi ansList;
bool flag = false;

int find(int j, vi arr)
{
    int mi = INT_MAX;
    int idx = 0;
    for (int i = j; i < arr.size(); i++)
    {
        if (mi > arr[i])
        {
            mi = arr[i];
            idx = i;
        }
    }
    return idx;
}

int reversort(vi arr)
{
    int cost = 0;
    for (int i = 1; i < arr.size() - 1; i++)
    {
        int j = find(i, arr);
        cost += j - i + 1;
        // cout<<i<<j<<"\n";
        reverse(arr.begin() + i, arr.begin() + j + 1);
        // for (int i : arr)
        //     cout << i << " ";
        // cout<<"\n";

        // cout<<cost<<"\n";
    }
    return cost;
}

void backTrack(vi list, int n, int start, int c)
{
    if (flag)
    {
        return;
    }
    vi array(list.size());
    for (int i = 0; i < list.size(); i++)
    {
        array[i] = list[i];
        // cout<<array[i]<<" ";
    }
    if (reversort(array) == c)
    {
        // cout<<reversort(array)<<"<-- ";
        ansList = list;
        // for(int i : ansList)
        // cout<<i<<" ";
        flag = true;
    }
    for (int i = start + 1; i < n; i++)
    {
        vi curr = list;
        swap(curr[start], curr[i]);
        backTrack(curr, n, start + 1, c);
    }
}

void reversortEngineering(int t, int c)
{
    vi a(t + 1, 0);
    for (int i = 1; i <= t; i++)
        a[i] = i;

    backTrack(a, t, 1, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int num = 1;
    while (num <= t)
    {
        int T, C;
        cin >> T >> C;
        ansList.clear();
        flag = false;
        reversortEngineering(T, C);

        if (!flag)
        {
            cout << "Case #" << num << ": IMPOSSIBLE\n";
        }
        else
        {
            string ans = "";
            for (int i = 1; i < ansList.size(); i++)
            {
                // cout<<ansList[i]<<" ,,,";
                ans += to_string(ansList[i]);
                ans += " ";
            }
            cout << "Case #" << num << ": " << ans << "\n";
        }
        num++;
    }
    return 0;
}

/* 
5
4 6
2 1
7 12
7 2
2 1000 

*/
