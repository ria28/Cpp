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

// give count of binary strings upto n such that there should be no consecutive zeros

void binary(int n)
{
    int next_zero = 0;
    int next_one = 0;
    int prev_zero = 1; // 0
    int prev_one = 1;  // 1
    for (int i = 1; i <=n; i++)
    {      
        next_zero = prev_one;
        next_one = prev_one + prev_zero;
        prev_zero = next_zero;
        prev_one = next_one;
        // cout << next_zero << " " << next_one << "\n";
    }
    cout << next_one;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 6;
    binary(n);
    return 0;
}