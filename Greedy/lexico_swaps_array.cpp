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

// O(n2)

void solve(vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n - 1 && k > 0; i++) // second last ele co we need to swap
    {
        int pos = i;
        for (int j = i + 1; j - i <= k; j++)
        {
            cout << arr[j] << arr[pos] << " ";
            if (arr[j] < arr[pos])
                pos = j;
        }
        cout << pos << "<-- ";
        for(int l=pos;l>0;l--)
        {
            swap(arr[l], arr[l-1]);
            k--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {7, 6, 9, 2, 1};
    solve(arr, arr.size(), 3);
    for (int i : arr)
        cout << i;
    return 0;
}