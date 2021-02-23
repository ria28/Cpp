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

// paint the fence (n) with k colors in such a way that not more that 2 consecutive / adjacent fences have same color
int numWays(int n, int k)
{
    if (n == 1)
        return k;
    int same, different; // last two till that cell
    int total = 0;
    // start with assigning values to the first two fences, start the loop from three
    same = k;
    different = k * (k - 1); // different -->permutation K * (K-1)
    total = same + different;
    for (int i = 3; i <= n; i++)
    {
        int curr_same = different;      // will add color in different o/w if added in the same of prev one the that would generate  3  same colors
        int curr_dif = total * (k - 1); // k-1 because it should not be same as the last color of the prev one

        same = curr_same;
        different = curr_dif;
        total = same + different;
        // cout << total << " ";
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 5, k = 3;
    // n = fences , k = colors
    cout << numWays(n, k);
    return 0;
}