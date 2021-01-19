#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// Input : coin[] = {100, 20, 50, 10, 2, 5},
//         k = 3
// Output : 7

// The ques says that if I pick a coin , I can pick 'k' more coins. So in total after the first pick I will have k+1 coins.
// remaining coins = n - (k+1). We will do this till n becomes 0 i.e, we have got all the coins.
// Here k =3 ==> I will have 4 coins in total after the first pick. Remaining:  6 - 4 =2 coins.
// So I will pick another coin and i have an option to pick 3 more but we have exhausted with our coins. So in total we need to pick 2 coins.

// sorted array : { 2,5,10,20,50,100}
// We need to choose min amount of coin so we sort the array. traverse till 2 coins , add them to your sum which comes out to be 2+5 ie 7.

// we are picking up the coin (k+1) * x times which should be equal to no of coins

void k_min(vector<int> &coin, int n, int k)
{
    int noOfPicks = ceil(1.0 * n / (k + 1));
    sort(coin.begin(), coin.end());
    int sum = 0;
    for (int i = 0; i < noOfPicks; i++)
    {
        sum += coin[i];
    }

    cout << sum << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coin = {100, 20, 50, 10, 2, 5};
    k_min(coin, coin.size(), 3);
    return 0;
}