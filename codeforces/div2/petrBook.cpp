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
    int n;
    cin >> n;
    vi arr(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int i = 0;
    while (1)
    {
        sum += arr[i];
        if (sum >= n)
            break;
        i = (i + 1) % 7;
    }
    cout << (i+1);
    cout << "\n";
    return 0;
}