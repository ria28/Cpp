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

//  https://www.geeksforgeeks.org/minimum-sum-two-numbers-formed-digits-array-2/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {6, 8, 4, 5, 2, 3};
    // 5, 3, 0, 7, 4
    sort(arr.begin(), arr.end());

    int n1 = 0, n2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            n1 = (10 * n1) + arr[i];
        }
        else
        {
            n2 = (10 * n2) + arr[i];
        }
    }
    cout << n1 + n2;

    return 0;
}