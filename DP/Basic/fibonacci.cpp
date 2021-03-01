#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// storage and meaning
// direction of problem
// travel and solve

ll fibonacci(ll n)
{
    if (n == 0 || n == 1)
        return n;
    ll fib_1 = fibonacci(n - 1);
    ll fib_2 = fibonacci(n - 2);
    ll fibo_n = fib_1 + fib_2;

    return fibo_n;
}

ll fibonacci_memo(ll n, vector<ll> &dp)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != 0)
        return dp[n];
    ll fib_1 = fibonacci_memo(n - 1, dp);
    ll fib_2 = fibonacci_memo(n - 2, dp);
    ll fibo_n = fib_1 + fib_2;

    dp[n] = fibo_n;
    return fibo_n;
}

void fibonacci_tab(ll n)
{
    vector<ll> tab(n + 1);
    tab[0] = 0;
    tab[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 2; j > 0; j--)
        {
            if (i - j >= 0)
            {
                sum += tab[i - j];
            }
        }

        tab[i] = sum;
    }
    cout << tab[n];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // ll n = 10; //55
    // cout << fibonacci(50);
    ll n = 50;
    vector<ll> dp(n + 1, 0);
    // cout << fibonacci_memo(n, dp);

    fibonacci_tab(n);
    return 0;
}