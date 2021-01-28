#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// https://leetcode.com/problems/counting-bits/

// So, for all even numbers, number of ones will be always the same as their halves.
// For odd numbers, subtracting one from it will make it an even number. So, number of ones in the even number + the one we subtracted.

/* 
    Even Numbers

    Number	Binary	Ones
    2	    10	    1
    4	    100	    1
    6	    110	    2
    12	    1100	2
    24	    11000	2
    
    Odd Numbers

    Number	        Binary	        Ones
    3 (2 + 1)	11 (10 + 01)	    2
    7 (6 + 1)	111 (110 + 001)	    3 
*/

vector<int> countBits(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i / 2] + i % 2;
    }
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for (auto i : countBits(num))
        cout << i << " ";
    return 0;
}