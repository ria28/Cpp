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




bool comparison(pair<int, int> a, pair<int, int> b)
{
    return ((a.first / a.second) > (b.first / b.second));
}


void fractionalKnap(vector<pair<int, int>> &arr, int w)
{
    sort(arr.begin(), arr.end(), comparison);
    int profit = 0;

    // {{60, 10}, {100, 20}, {120, 30}}
    //   6          5           4

    for (int i = 0; i < arr.size(); i++)
    {
        if (w == 0)
            break;

        if (arr[i].second <= w)
        {
            w -= arr[i].second;
            profit += arr[i].first;     // w = 50 , 40 ,  20 , 0
        }
        else
        {
            profit += (w * arr[i].first) / arr[i].second;
            w = 0;
        }
    }

    cout << profit << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W = 50;
    vector<pair<int, int>> val_wt = {{60, 10}, {100, 20}, {120, 30}};

    fractionalKnap(val_wt, W);
    return 0;
}