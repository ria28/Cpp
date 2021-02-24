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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// approach : keep on finding the minimum while traversing the array.
// And keep on selling on each day to see whats the max profit that is find the profit by subtraction minimum so far with price of that day
int maxProfit(vector<int> &prices)
{
    int max_profit = INT_MIN;
    int min_so_far = INT_MAX; // buy;

    for (int i = 0; i < prices.size(); i++)
    {
        min_so_far = min(min_so_far, prices[i]);

        // if you sell today
        int curr_profit = prices[i] - min_so_far;
        max_profit = max(max_profit, curr_profit);
    }
    return max_profit;
}
void oneTransaction()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}

// ---------------------------------------------------------------------------------------------------------------------------

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
int maxProfit_infinite(vector<int> &prices)
{
    int max_profit = 0;
    int buy;
    int sell;

    int i = 0;
    int n = prices.size();
    if (n == 1)
        return 0;
    while (i < n)
    {
        while (i + 1 < n && prices[i + 1] <= prices[i])
            i++;
        buy = i;

        // i++;
        while (i + 1 < n && prices[i] <= prices[i + 1])
            i++;
        sell = i;
        // cout << buy << sell<<"\n";
        max_profit += prices[sell] - prices[buy];
        i++;
    }
    return max_profit;
}
void infiniteTransactions()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit_infinite(prices);
}

// ---------------------------------------------------------------------------------------------------------------------------

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
int maxProfit_infinite_fees(vi &prices, int fee)
{
    int old_bsp = -prices[0]; // old bought state profit
    int old_ssp = 0;          // new sell state profit
    for (int i = 1; i < prices.size(); i++)
    {
        int new_bsp = 0;
        int new_ssp = 0;

        if (old_ssp - prices[i] > old_bsp) //we have negative bsp (loan)  -10 > -15
            new_bsp = old_ssp - prices[i];
        else
            new_bsp = old_bsp;

        if (prices[i] + old_bsp - fee > old_ssp)
            new_ssp = prices[i] + old_bsp - fee;
        else
            new_ssp = old_ssp;

        old_bsp = new_bsp;
        old_ssp = new_ssp;
    }
    return old_ssp;
}
void infiniteTransactions_transactionFees()
{
    vi prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit_infinite_fees(prices, fee);
}

// ---------------------------------------------------------------------------------------------------------------------------

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
int maxProfit_coolDown(vi &prices)
{
    if (prices.size() == 0)
        return 0;

    int old_bsp = -prices[0];
    int old_ssp = 0;
    int old_csp = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        int new_bsp = 0;
        int new_ssp = 0;
        int new_csp = 0;

        if (old_csp - prices[i] > old_bsp)
            new_bsp = old_csp - prices[i];
        else
            new_bsp = old_bsp;

        if (old_bsp + prices[i] > old_ssp)
            new_ssp = old_bsp + prices[i];
        else
            new_ssp = old_ssp;

        if (old_ssp > old_csp)
            new_csp = old_ssp;
        else
            new_csp = old_csp;

        old_bsp = new_bsp;
        old_ssp = new_ssp;
        old_csp = new_csp;
    }
    return old_ssp;
}
void infiniteTransactions_coolDown()
{
    vi prices = {1, 2, 3, 0, 2};
    cout << maxProfit_coolDown(prices);
}

// ---------------------------------------------------------------------------------------------------------------------------

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

int maxProfit_twoTransactions(vi &prices)
{
    /* 
        2 traversals 
            1. Left to right : which calculates MAX profit till then by selling on that day or before.
            2. Right to Left : calc MAX profit on that day if the shares are bought on either that day or after it.
    */

    // left to right
    int lsf = prices[0]; // least so far
    vi dp_left(prices.size(), -1);
    dp_left[0] = 0; // not possible to sell on the very first day so 0

    for (int i = 1; i < dp_left.size(); i++)
    {
        if (lsf > prices[i])
            lsf = prices[i];

        if (prices[i] - lsf > dp_left[i - 1])
        {
            dp_left[i] = prices[i] - lsf;
        }
        else
        {
            dp_left[i] = dp_left[i - 1];
        }
    }

    // right to left
    int msf = prices[prices.size() - 1];
    vi dp_right(prices.size(), -1);
    dp_right[prices.size() - 1] = 0;

    for (int i = prices.size() - 2; i > 0; i--)
    {
        if (msf < prices[i])
            msf = prices[i];

        dp_right[i] = max(dp_right[i + 1], msf - prices[i]);
    }

    int max_profit = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        max_profit = max(max_profit, dp_left[i] + dp_right[i]);
    }
    return max_profit;
}

void twoTransactions()
{
    vi prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit_twoTransactions(prices);
}

void kTransactions()
{
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // oneTransaction();
    // infiniteTransactions();
    // infiniteTransactions_transactionFees();
    // infiniteTransactions_coolDown();
    twoTransactions();
    kTransactions();

    return 0;
}