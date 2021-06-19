#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

vector<bool> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    // for (auto i : primes)
    //     cout << i << " ";
    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
    {
        // i : prime no
        //  max(i * i, (L + i - 1) / i * i) or take ceil (L/i) * i and loop , inc with i to mark multiples like in sieves 

        long long factor = ceil(L / (i*1.0));
        for (long long j = max(i * i,factor*i); j <= R; j += i)     // L=2 , R =10 -> avoiding 2 marking 2 as non prime by taking max : max(2*2 , [3/2]*2) = max(4 ,2) =4
        {
            cout<<j<<" ";
            isPrime[j - L] = false;
        }
    }
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    segmentedSieve(70, 100);
    return 0;
}